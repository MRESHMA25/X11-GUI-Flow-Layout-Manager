
#include "TextArea.h"
#define SPACE 32
#define LEFT_MARGIN 7
#define TOTAL_MARGIN 10

TextArea::TextArea(int x, int y, int width, int height,  const string& id, const string& text){
    dimensions = {x, y, width, height};
    this->text = text;
    this->fill = RGB::WHITE();
    this->border = RGB::BLACK();
    this->id = id;

    lastDrawn = {0,0,0,0};
}

TextArea::TextArea(const Rectangle& rect, const string& id, const string& text){
    dimensions = rect;
    this->id = id;
    this->text = text;
    this->fill = RGB::WHITE();
    this->border = RGB::BLACK();

    lastDrawn = {0,0,0,0};
}




TextArea::~TextArea(){
    // nothing to do here
}

bool TextArea::overlaps(const TextArea& textArea) const{
    return dimensions.overlaps(textArea.dimensions);
}

//setters

void TextArea::setSize(int width, int height){
    dimensions.width = width;
    dimensions.height = height;
}

void TextArea::setWidth(int width){
    dimensions.width = width;
}

void TextArea::setHeight(int height){
    dimensions.height = height;
}

//getters

int TextArea::getX() const{return dimensions.x;}

int TextArea::getY() const{return dimensions.y;}

int TextArea::getWidth() const{
    return dimensions.width;
}

int TextArea::getHeight() const{
    return dimensions.height;
}

const string& TextArea::getText() const{
    return text;
}

const string& TextArea::getId() const{
    return id;
}


string TextArea::getNextLine(const string& text, int start, int width, XFontStruct* font_info) const{
    int currentLength = text.length()-start;
    int text_width = XTextWidth(font_info, text.substr(start, currentLength).c_str(), currentLength);
    while (text_width > width){
        currentLength--;
        text_width = XTextWidth(font_info, text.substr(start, currentLength).c_str(), currentLength);
    }

    // The rest of the string fits, so simply return it
    if (currentLength == text.length()-start){
        return text.substr(start, currentLength);
    }

    // We have to cut the string somewhere, so we walk backwards until we find a space
    int savedLength = currentLength; 
    while (text.substr(start+currentLength,1).c_str()[0] != SPACE){
        currentLength--;
        if (currentLength == 0){
            // We could not find a space, so we just return the substring.
            // This will cut some word someplace, but text editing is hard.
            return text.substr(start, savedLength);
        }
    }
    
    // We found a space, so we return the substring up to and including that space (+1 includes the space)
    // We print the space on this line, otherwise it will start the next line and look dumb.
    return text.substr(start, currentLength+1);
    
    
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {

    int width = dimensions.width;
    int height = dimensions.height;

    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, width, height);
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, width, height);

    // We will use this in a future assignment
    lastDrawn = {x, y, dimensions.width, dimensions.height};
    
    // Getting a new font struct each time is not efficient, but it works!! 
    // Working code is better than good design. We can improve this design later.

    const char* font_name = "fixed"; // You can specify a different font
    XID font = XLoadFont(display, font_name);
    XFontStruct* font_info = XQueryFont(display, font);
    if (!font_info) {
        cerr<<"Failed to query font"<<endl;
        return; 
    }

    XSetFont(display, gc, font);
    // The height of the text
    int text_height = font_info->ascent + font_info->descent;
    int currentStart = 0;

    int currentLine = 1;

    // cout<<"Current height: "<<text_height<<endl;
    
    while(currentStart < text.length()){
        string nextLine = getNextLine(text, currentStart, width-TOTAL_MARGIN, font_info);
        
        // draw the substring in the appropriate place
        XDrawString(display, win, gc, x+LEFT_MARGIN, y + ((text_height)*currentLine), nextLine.c_str(), nextLine.length());
        // 
        currentLine++;
        // the next line would stick out of the bottom of the TextArea, so we are done writing
        if (((text_height)*currentLine)>height){
            break;
        }
        // The start of the next substring
        currentStart += nextLine.length();  
    }


    // Cleanup
    XFreeFontInfo(NULL, font_info, 1);
    
    // cout<<"Called draw on TextArea"<<endl;
}


void TextArea::setFill(const RGB& fill){
    this->fill = fill;
}

void TextArea::setBorder(const RGB& border){
    this->border = border;
}

void TextArea::setText(const string& text){
    this->text = text;
}

void TextArea::print() const{
    cout<<"TextArea:           "<<id<<endl;
    cout<<"Preferred Location: "<<dimensions.x<<", "<<dimensions.y<<endl;
    cout<<"Size:               "<<dimensions.width<<", "<<dimensions.height<<endl;
    cout<<"Text:               "<<text<<endl;
}