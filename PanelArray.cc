#include "PanelArray.h"

PanelArray::PanelArray()
{
    size = 0;
    panels = new FlowPanel*[MAX_COMPONENTS];
}

PanelArray::~PanelArray(){
    // for (int i = 0; i < size; i++)
    // {
    //     delete panels[i];
    // }
    delete[] panels;
}

bool PanelArray::add(FlowPanel* panel)
{
    if (size >= MAX_COMPONENTS)
    {
        return false;
    }
    for(int i = 0; i < size; i++)
    {
        if (panels[i]->overlaps(*panel))
        {
            return false;
        }
    }
    panels[size] = panel;
    size++;
    return true;
}

FlowPanel* PanelArray::remove(const string& id){
    for (int i = 0; i < size; i++)
    {
        if (panels[i]->getId() == id)
        {
            FlowPanel* panel = panels[i];
            for (int j = i; j < size - 1; j++)
            {
                panels[j] = panels[j + 1];
            }
            size--;
            return panel;
        }
    }
    return nullptr;
}

FlowPanel* PanelArray::remove(int index){
    if (index < 0 || index >= MAX_COMPONENTS || size >= MAX_COMPONENTS)
    {
        cout<<"Invalid index"<<endl;
        return nullptr;
    }
    FlowPanel* panel = panels[index];
    for (int i = index; i < size - 1; i++)
    {
        panels[i] = panels[i + 1];
    }
    size--;
    return panel;
}

FlowPanel* PanelArray::get(const string& id) const{
    for (int i = 0; i < size; i++)
    {
        if (panels[i]->getId() == id)
        {
            return panels[i];
        }
    }
    cout<<"Panel not found"<<endl;
    return nullptr;
}

FlowPanel* PanelArray::get(int index) const{
    if (index < size && index >= 0)
    {
        return panels[index];
    }
    return nullptr;
}