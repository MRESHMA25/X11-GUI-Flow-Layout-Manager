# X11 GUI Flow Layout Manager

## Overview
This project is a C++ application built on top of X11 that manages GUI components using a flow layout system. It features user-defined classes for panels, text areas, color management, and dynamic collections to create and manage a simple graphical interface.

Key design aspects include:
- Object-Oriented Architecture (Entities, Control, View, and Collection classes)
- Flow layout implementation for placing text areas dynamically within panels
- Manual memory management with dynamic allocation and proper cleanup
- Console printing utilities for all core objects
- Simple text wrapping and collision detection between GUI components

## Project Structure

| File                    | Purpose                                                             |
| ----------------------- | ------------------------------------------------------------------- |
| RGB.h/.cc               | Manage RGB color operations and provide static predefined colors.  |
| TextArea.h/.cc          | Define and draw text areas with customizable content and colors.   |
| TAArray.h/.cc           | Dynamic array management for multiple text areas.                  |
| FlowPanel.h/.cc         | Flow layout panel that organizes text areas dynamically.           |
| PanelArray.h/.cc        | Dynamic array management for multiple flow panels.                 |
| CuWindow.h/.cc          | Manage the main window, event handling, and organize panels.       |
| Rectangle.h             | Struct to represent rectangle dimensions and overlaps.             |
| defs.h                  | Constants and global definitions for GUI settings.                 |
| TestControl.h/.cc       | Controls the interaction between user interface and test cases.    |
| Tester.h/.cc            | Executes tests to verify functionality of components.              |
| View.h/.cc              | Handles user input and menu display for interaction.               |
| main.cc                 | Launch and manage the application and initiate testing.            |
| Makefile                | Build instructions for compiling the project.                      |

## Features
- **CuWindow**: Manages a graphical X11 window and multiple panels.
- **FlowPanel**: Arranges TextArea components using a left-to-right, top-to-bottom flow layout.
- **TextArea**: Represents text boxes that are placed inside panels, with basic text wrapping.
- **PanelArray and TAArray**: Custom dynamic arrays for managing collections.
- **RGB**: Provides basic color utilities with predefined static color methods (e.g., `WHITE()`, `RED()`, etc.)
- **Memory Management**: Ownership and cleanup of dynamic memory are handled carefully within classes.

## Build Instructions

Run any of the following commands in your terminal:
make  
or  
make all  
or  
make a2  

This will generate an executable named `a2`.

---

## Running the Application

After compilation, run:

./a2

## Notes

- FlowPanel implements a basic flow layout: elements are laid out horizontally with wrapping to the next row if needed.
- Dynamic memory usage is carefully managed with copy constructors and destructors.
- Layout behaviors and testing results are printed to the console.
- The application demonstrates basic text wrapping within TextArea boundaries (text does not overflow outside its box).

This program was created by @MRESHMA25
