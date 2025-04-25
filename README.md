# X11 GUI Flow Layout Manager in C++

This project provides a lightweight object-oriented framework for creating graphical user interfaces (GUIs) using the X11 windowing system in C++. It includes core classes for managing windows, flow panels, and text areas, with custom color handling, dynamic collections, and proper memory management.

---

## Features

- RGB Color Management: Simple conversions between RGB values and X11 color format.
- TextArea Class: Create and render text areas with custom sizes, labels, and colors.
- FlowPanel Class: Organize text areas inside panels with a dynamic flow layout.
- CuWindow Class: Manage the overall application window, background, and GUI elements.
- Overlapping Detection: Panels and text areas detect and prevent layout issues.
- Custom Drawing: Rendering handled manually through X11 library calls for flexibility.

---

## Project Structure

| File                   | Purpose                                                             |
| ---------------------- | ------------------------------------------------------------------- |
| RGB.h/.cc               | Manage RGB color operations and provide static predefined colors.  |
| TextArea.h/.cc          | Define and draw text areas with customizable content and colors.    |
| TAArray.h/.cc           | Dynamic array management for multiple text areas.                  |
| FlowPanel.h/.cc         | Flow layout panel that organizes text areas dynamically.           |
| PanelArray.h/.cc        | Dynamic array management for multiple flow panels.                 |
| CuWindow.h/.cc          | Manage the main window, event handling, and organize panels.        |
| Rectangle.h             | Struct to represent rectangle dimensions and overlaps.             |
| defs.h                  | Constants and global definitions for GUI settings.                 |
| TestControl.h/.cc       | Controls the interaction between user interface and test cases.    |
| Tester.h/.cc            | Executes tests to verify functionality of components.              |
| View.h/.cc              | Handles user input and menu display for interaction.               |
| main.cc                 | Launch and manage the application and initiate testing.            |
| Makefile                | Build instructions for compiling the project.                      |

---

### Build Instructions

Run any of the following commands in your terminal:

make  
or  
make all  
or  
make a2  

This will generate an executable named a2.

---

## Running the Application

After compilation, run:

./a2  

This will open a window displaying panels and text areas, demonstrating GUI management and rendering functionalities.

---

## Notes

- The Tester class is used to validate the functionality of the framework.
- Memory management, deep copying, and array bounds are carefully handled.
- Only standard C++ libraries (iostream, string, sstream, iomanip, unistd) are used.
- No external libraries beyond X11 are required.

This program was created by @MRESHMA25
