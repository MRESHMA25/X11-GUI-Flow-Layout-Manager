#include "RGB.h"

RGB::RGB(int r, int g, int b){
    this->r = r;
    this->b = b;
    this->g = g;
}

RGB::RGB(CuColour colour){
    r = (colour >> 16) & 0xFF;
    g = (colour >> 8) & 0xFF;
    b = colour & 0xFF;
}

RGB::RGB(){
    r = 0;
    b = 0;
    g = 0;
}

void RGB::setColour(CuColour colour){
    r = (colour >> 16) & 0xFF;
    g = (colour >> 8) & 0xFF;
    b = colour & 0xFF;
}

int RGB::getR() const{
    return r;
}

int RGB::getB() const{
    return b;
}

int RGB::getG() const{
    return g;
}

void RGB::setR(int r){
    this->r = r;
}

void RGB::setB(int b){
    this->b = b;
}

void RGB::setG(int g){
    this->g = g;
}

CuColour RGB::getColour() const{
    return (r << 16) + (g << 8) + b;
}