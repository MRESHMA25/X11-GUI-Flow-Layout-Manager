#include "TAArray.h"

TAArray::TAArray()
{
    size = 0;
    taArray = new TextArea*[MAX_COMPONENTS];
}

TAArray::~TAArray(){
    // for (int i = 0; i < size; i++)
    // {
    //     delete taArray[i];
    // }
    delete[] taArray;
}

bool TAArray::add(TextArea* ta)
{
    if (size >= MAX_COMPONENTS)
    {
        return false;
    }
    taArray[size] = ta;
    size++;
    return true;
}

bool TAArray::add(TextArea* ta, int index)
{
    if (index < 0 || index >= MAX_COMPONENTS || size >= MAX_COMPONENTS)
    {
        return false;
    }
    for (int i = size; i > index; i--)
    {
        taArray[i] = taArray[i - 1];
    }
    taArray[index] = ta;
    size++;
    return true;
}

TextArea* TAArray::remove(const string& id){
    for (int i = 0; i < size; i++)
    {
        if (taArray[i]->getId() == id)
        {
            TextArea* ta = taArray[i];
            for (int j = i; j < size - 1; j++)
            {
                taArray[j] = taArray[j + 1];
            }
            size--;
            return ta;
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index){
    if (index < 0 || index >= size)
    {
        return nullptr;
    }
    TextArea* ta = taArray[index];
    for (int i = index; i < size - 1; i++)
    {
        taArray[i] = taArray[i + 1];
    }
    size--;
    return ta;
}

TextArea* TAArray::get(const string& id) const{
    for (int i = 0; i < size; i++)
    {
        if (taArray[i]->getId() == id)
        {
            return taArray[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::get(int index) const{
    if (index < size && index >= 0)
    {
        return taArray[index];
    }
    return nullptr;
}