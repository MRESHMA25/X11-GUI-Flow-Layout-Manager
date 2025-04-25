#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB{
    public :
        RGB(int r, int b, int g);
        RGB(CuColour colour);
        RGB();
        int getR() const;
        int getB() const;
        int getG() const;
        void setR(int r);
        void setB(int b);
        void setG(int g);
        void setColour(CuColour colour);

        static RGB WHITE(){
            return RGB(255, 255, 255);
        }

        static RGB BLACK(){
            return RGB(0,0,0);
        }

        static RGB RED(){
            return RGB(255, 0, 0);
        }

        static RGB GREEN(){
            return RGB(0, 255, 0);
        }

        static RGB BLUE(){
            return RGB(0, 0, 255);
        }

        CuColour getColour() const;

    private:
        int r;
        int b;
        int g;

};

#endif