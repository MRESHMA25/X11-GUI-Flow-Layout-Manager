
#include "FlowPanel.h"

FlowPanel::FlowPanel(int x, int y, int width, int height, const string& id, int xgap, int ygap){
    dim = {x, y, width, height};
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
    this->flow = true;
}

FlowPanel::FlowPanel(const Rectangle& rect, const string& id, int xgap, int ygap){
    dim = rect;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
    this->flow = true;
}

FlowPanel::FlowPanel(const FlowPanel& panel){
    this->dim = panel.dim;
    this->id = panel.id;
    this->xgap = panel.xgap;
    this->ygap = panel.ygap;
    this->flow = panel.flow;
    for (int i = 0; i < panel.textAreas.getSize(); i++){
        textAreas.add(new TextArea(*panel.textAreas.get(i)));
    }
}

FlowPanel::~FlowPanel(){
    for (int i = 0; i < textAreas.getSize(); i++){
        delete textAreas.get(i);
    }
}



void FlowPanel::setId(const string& id){
    this->id = id;
}

void FlowPanel::setSize(int width, int height){
    dim.width = width;
    dim.height = height;
}

void FlowPanel::setWidth(int width){
    dim.width = width;
}

void FlowPanel::setHeight(int height){
    dim.height = height;
}

void FlowPanel::setPosition(int x, int y){
    dim.x = x;
    dim.y = y;
}

void FlowPanel::setX(int x){
    dim.x = x;
}

void FlowPanel::setY(int y){
    dim.y = y;
}

//getters

const string& FlowPanel::getId() const{
    return id;
}

int FlowPanel::getX() const{
    return dim.x;
}

int FlowPanel::getY() const{
    return dim.y;
}

int FlowPanel::getWidth() const{
    return dim.width;
}

int FlowPanel::getHeight() const{
    return dim.height;
}


bool FlowPanel::addTextArea(TextArea* textArea){
    return textAreas.add(textArea);
}

bool FlowPanel::addTextArea(TextArea* textArea, int index){
    return textAreas.add(textArea, index);
}

TextArea* FlowPanel::removeTextArea(const string& id){
    return textAreas.remove(id);
}

TextArea* FlowPanel::removeTextArea(int index){
    return textAreas.remove(index);
}


TextArea* FlowPanel::getTextArea(const string& id) const{
    return textAreas.get(id);
}

TextArea* FlowPanel::getTextArea(int index) const{
    return textAreas.get(index);
}

void FlowPanel::draw(Display* display, Window win, GC gc){
    if (!flow){
        cout<<"FlowPanel: "<<id<<" is not in flow mode, drawing textAreas at absolute positions"<<endl;
        drawAbsolute(display, win, gc);
        return;
    } 

    /*
    * We want to draw these textAreas in a flow layout
    */
    int x = dim.x;
    int y = dim.y;
    int width = dim.width;
    int height = dim.height;
    XSetForeground(display, gc, 0xFFFFFF);
    XDrawRectangle(display, win, gc, x, y, width, height);

    int currentX = x + xgap;
    int currentY = y + ygap;
    int maxHeight = 0;

    int index = 0;
    while(index < textAreas.getSize()){
       TextArea* textArea = textAreas.get(index);
       if (textArea->getHeight()+currentY > y + height){
            // this won't fit, so stop here
            return;
       }
       if (currentX + textArea->getWidth()>x+width){
            // we are going to go outside of the Panel, so try the next row
            currentX = x + xgap;  // back to the front
            if (maxHeight == 0) return; // we only saw one textArea and it doesn't fit, so we're done
            currentY = currentY + maxHeight + ygap;
            continue;
       }

       // otherwise this textArea fits
       textArea->draw(display, win, gc, currentX, currentY);
       currentX += textArea->getWidth() + xgap;
       if (maxHeight < textArea->getHeight()){
            maxHeight = textArea->getHeight();
       }
       index ++;
   }
}

void FlowPanel::drawAbsolute(Display* display, Window win, GC gc){
    // XSetForeground(display, gc, 0x000000);
    // XFillRectangle(display, win, gc, x, y, width, height);
    XSetForeground(display, gc, 0xFFFFFF);
    XDrawRectangle(display, win, gc, dim.x, dim.y, dim.width, dim.height);
    for (int i = 0; i < textAreas.getSize(); i++){
        TextArea* ta = textAreas.get(i);
        ta->draw(display, win, gc, dim.x + ta->getX(), dim.y + ta->getY());
    }
}

bool FlowPanel::overlaps(const FlowPanel& panel) const{
    return dim.overlaps(panel.dim);
}

void FlowPanel::print() const{
    cout<<"FlowPanel:    "<<id<<endl;
    cout<<"Position:     "<<dim.x<<", "<<dim.y<<endl;
    cout<<"Size:         "<<dim.width<<", "<<dim.height<<endl;
    cout<<"TextAreas:    "<<textAreas.getSize()<<endl;
}

void FlowPanel::printTextAreas() const{
    for (int i = 0; i < textAreas.getSize(); i++){
        textAreas.get(i)->print();
        cout<<endl;
    }
}