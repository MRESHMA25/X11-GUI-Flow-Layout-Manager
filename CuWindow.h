#ifndef CuWindow_H
#define CuWindow_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "defs.h"
#include "PanelArray.h"
#include "RGB.h"

using namespace std;

class CuWindow {
	friend void* eventThread(void *);
	public:
		//constructor
		CuWindow(const string& name, int width, int height, const RGB& color);
		~CuWindow();

		

		bool       addPanel(FlowPanel* panel);
		FlowPanel* removePanel(const string& id);
		FlowPanel* getPanel(const string& id) const;

		void draw() const;
		
		void print() const;
		void printPanels() const;
		void printPanelTextAreas() const;

	
	
	private:
		bool fitsWindow(FlowPanel* panel);
		Display *display;
		Window   win;
		GC       gc;

		int width;
		int height;
		RGB background;

		string name; 

		PanelArray panels;

	
	
};
#endif