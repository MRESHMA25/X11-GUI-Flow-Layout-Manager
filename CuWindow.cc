
#include "CuWindow.h"
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

// comment this out to turn off thread based redrawing
#define REDRAW

// some global thread stuff for redrawing the window
pthread_t eventThreadID;
bool running = true;
void* eventThread(void* window){
    CuWindow* win = (CuWindow*) window;
    XEvent event;
    while(running){
        if (XPending(win->display) == 0){
            usleep(10000);
            continue;
        }
        XNextEvent(win->display, &event);
        if (event.type == Expose || event.type == ConfigureNotify){
            win->draw();
        }
        if (event.type == ButtonPress){
            cout<<"Mouse Button Pressed"<<endl;
            // win->registerClick(event.xbutton.x, event.xbutton.y);
            // win->draw();
        }
        if (event.type == ButtonRelease){
            cout<<"Mouse Button Released"<<endl;
            // win->unClickAll();
            // win->draw();
        }
        // usually a bunch of events build up,
        // so clear the event queue
        while (XPending(win->display)){
            XNextEvent(win->display, &event);
        }
    }
    return NULL;
}


CuWindow::CuWindow(const string& name, int width, int height, const RGB& color){
    this->width = width;
    this->height = height;
    display = XOpenDisplay(NULL);
    if (display == NULL){
        cerr<<"Cannot open display"<<endl;
        exit(1);
    }

    this->name = name;
    background = color;

    win = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0,
                    width, height, 0, 0x000000, background.getColour());


    XStoreName(display, win, name.c_str());
    gc = XCreateGC(display, win, 0, NULL);
    XMapWindow(display, win);
    XFlush(display);

    #ifdef REDRAW
        XSelectInput(display, win,
            ButtonPressMask | // When Mouse Button is Pressed
            ButtonReleaseMask | // When Mouse Button is Released
            ExposureMask |      // When window is exposed
            StructureNotifyMask // When there is a change in window structure
            );
        pthread_create(&eventThreadID, NULL, eventThread, this);
    #endif

    usleep(20000);     
}


CuWindow::~CuWindow(){
    
    #ifdef REDRAW
        running = false;
        pthread_join(eventThreadID, NULL);
    #endif
    // close the window
    XFreeGC(display, gc);
    XDestroyWindow(display, win);
    XCloseDisplay(display);
    

    // delete all panels
    for(int i = 0; i < panels.getSize(); i++){
        delete panels.get(i);
    }
}

bool CuWindow::fitsWindow(FlowPanel* panel){
    if (panel->getX()+panel->getWidth() > width
    || panel->getY()+panel->getHeight() > height){
        return false;
    }
    return true;
}


bool CuWindow::addPanel(FlowPanel* panel){
    
    if (panels.isFull()) return false;
    if (!fitsWindow(panel)) return false;
    return panels.add(panel);

}

FlowPanel* CuWindow::removePanel(const string& id){
    return panels.remove(id);
}


FlowPanel* CuWindow::getPanel(const string& id) const{
    return panels.get(id);
}

void CuWindow::draw() const{
    // draw the window
    usleep(100000);
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, win, gc, 0, 0, width, height);

    for (int i = 0; i < panels.getSize(); i++){
        panels.get(i)->draw(display, win, gc);
    }

    XFlush(display);

}


void CuWindow::print() const{
    cout<<"Window: "<<name<<endl;
    cout<<"Panels: "<<panels.getSize()<<endl;
    
}

void CuWindow::printPanels() const{
    for (int i = 0; i < panels.getSize(); i++){
        panels.get(i)->print();
    }
}

void CuWindow::printPanelTextAreas() const{
    for (int i = 0; i < panels.getSize(); i++){
        panels.get(i)->printTextAreas();
    }
}