#include <iostream>
#include "FlowPanel.h"


using namespace std;


class PanelArray
{       
    public:
        PanelArray();
        ~PanelArray();

        bool add(FlowPanel* panel);
        FlowPanel* remove(const string& id);
        FlowPanel* remove(int index);
        FlowPanel* get(const string& id) const;
        FlowPanel* get(int index) const;
        int getSize() const{return size;}
        bool isFull(){return size == MAX_COMPONENTS;}
    
    private:
        int size;
        FlowPanel** panels;



};