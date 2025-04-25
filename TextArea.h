#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "RGB.h"

using namespace std;

class TextArea {
		
	public:
		//constructor
		TextArea(int x, int y, int width, int height, const string& id, const string& text);
		TextArea(const Rectangle& rect, const string& id, const string& text);
		//destructor
		~TextArea();
		

		void draw(Display *display, Window win, GC gc, int parentX, int parentY);	
		bool overlaps(const TextArea& textArea) const;

		//setters
	
		void setSize(int width, int height);
		void setWidth(int width);
		void setHeight(int height);
		void setText(const string& text);
		void setFill(const RGB& fill);
		void setBorder(const RGB& border);

		//getters
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		const string& getText() const;
		const string& getId() const;
	
		void print() const;
	
	private:
		string getNextLine(const string& text, int start, int width, XFontStruct* font_info) const;
		Rectangle dimensions;
		string text;
		string id;
		RGB fill;
		RGB border;
		Rectangle lastDrawn;
	
};
#endif