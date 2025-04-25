#include <iostream>
#include "TextArea.h"


using namespace std;


class TAArray
{       
    public:
        TAArray();
        ~TAArray();

        bool add(TextArea* ta);
        bool add(TextArea* ta, int index);
        TextArea* remove(const string& id);
        TextArea* remove(int index);
        TextArea* get(const string& id) const;
        TextArea* get(int index) const;
        int getSize() const{return size;}
        bool isFull() const{return size == MAX_COMPONENTS;}
    
    private:
        int size;
        TextArea** taArray;

};