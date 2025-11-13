# To-Do List (C++ Data Structures Project)

## Overview: 
Console-based To-Do List implemented in C++ using array and linked list data structures to demonstrate the List Abstract Data Type (ADT). This project highlights core C++ concepts including templates, class inheritance, and dynamic memory management.

---

## Features:
- Add, remove, and view tasks through a menu-driven console interface  
- Two underlying storage models:
  - **ArrayList** — static array implementation
  - **LinkedList** — dynamic, pointer-based implementation
- Demonstrates templates, class inheritance, and interface design  
- Efficient memory management and modular code structure  

---

## Installation:
1. Clone the repository
```bash
git clone https://github.com/1106-Guillebeau-Georgia/To-Do-List-CPP-Data-Structures-Project.git
```

2. Compile the program
```bash
make
```

---
## Usage:

After compiling the program, run it from the console:
```bash
./driver
```

Example Output:
``` text
TODO APP
1. Add task to do
2. Complete task
3. Display TODO list
4. Display DONE list
0. Exit 
1
No tasks currently!

What is the priority of your new task?
1
What is your new task?
Clean Room

TODO APP
1. Add task to do
2. Complete task
3. Display TODO list
4. Display DONE list
0. Exit 
1
1: Clean Room

What is the priority of your new task?
1
What is your new task?
Walk Dog

TODO APP
1. Add task to do
2. Complete task
3. Display TODO list
4. Display DONE list
0. Exit 
2

To Do: 
1: Walk Dog
2: Clean Room
Please select which task you've completed: 
1

Completed: 
1: Walk Dog

TODO APP
1. Add task to do
2. Complete task
3. Display TODO list
4. Display DONE list
0. Exit 
4

Completed: 
1: Walk Dog

TODO APP
1. Add task to do
2. Complete task
3. Display TODO list
4. Display DONE list
0. Exit 
0
```

## Technologies 
- C++ Programming Language
- Object-Oriented Programming (OOP)
- Abstract Data Types (ADT)
- Templates and Class Inheritance
- Dynamic Memory Management (Pointers)
- Arrays and Linked List Data Structures 
- Makefile for compilation automation

## Notes
  - Input validation is minimal; the program assumes the user enters valid integers for menu selections.
  - Focus of this project is on implementing the List ADT using array and linked list storage, as well as      analyzing the time complexity difference between them.
  - The main driver (`main.cpp`) was provided the instructor as part of a course assignment.  
  - All data structure implementations (`LinkedList`, `ArrayList`, `Node`, etc.) were written and debugged     by me.
 
## About
  Created by Georgia Guillebeau — Computer Science & Engineering student at UNR.
  [LinkedIn](https://www.linkedin.com/in/georgia-guillebeau-3b3636285)
