#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>

#include "defs.h"
#include "TAArray.h"

using namespace std;

class FlowPanel {
		
	public:
		//constructor
		FlowPanel(int x, int y, int width, int height, const string& id, int xgap = 10, int ygap = 10);
		FlowPanel(const Rectangle& rect, const string& id, int xgap = 10, int ygap = 10);

		FlowPanel(const FlowPanel& panel);

		//destructor
		~FlowPanel();

		bool      addTextArea(TextArea* textArea);
		bool 	  addTextArea(TextArea* textArea, int index);
		TextArea* getTextArea(const string& id) const;
		TextArea* getTextArea(int index) const;
		TextArea* removeTextArea(const string& id);
		TextArea* removeTextArea(int index);

		// setters
		void setId(const string& id);
		void setPosition(int x, int y);
		void setX(int x);
		void setY(int y);
		
		void setSize(int width, int height);
		void setWidth(int width);
		void setHeight(int height);

		// getters
		const string& getId() const;
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;

		void draw(Display *display, Window win, GC gc);

		bool overlaps(const FlowPanel& panel) const;
		
		void print() const;
		void printTextAreas() const;
	
	private:
		void drawAbsolute(Display *display, Window win, GC gc);

		Rectangle dim;
		int xgap;
		int ygap;
		string id;

		bool flow;

		TAArray textAreas;


	
};
#endif