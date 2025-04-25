#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "CuWindow.h"
#include "View.h"
#include "Tester.h"

using namespace std;


class TestControl
{
  public:
    
    void launch();
    

  private:
    int testTextAreas();
    int testFlowPanels();
    int testTextAreasinFlowPanel();

    // Integration tests for CuWindow
    int testFlowPanelsinWindow();

    // deprecated
    int mwTestTextAreas();

    int testFlowPanelMemory();
    int testWindowMemory();

    void testRenderWindow();

    void studentTests();
  

    View view;
    Tester tester;

    static vector<string> menu;



    
};

#endif
