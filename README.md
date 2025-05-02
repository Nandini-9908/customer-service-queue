This is a simple C++ console-based Call Log System that manages customer calls using a doubly linked list. It simulates a basic call queue, allowing users to:
Add new customer calls
Remove the oldest call
View all call logs with timestamps

Features
Uses a doubly linked list to store call logs
Each call log includes:
Customer name
Timestamp (automatically recorded at the time of entry)
Menu-driven interface for user interaction

How It Works
Calls are added to the tail (newest end) of the queue.
The oldest call (head of the queue) can be removed.
All logs can be displayed in chronological order.

Compilation

To compile the program, use a C++ compiler such as g++:
g++ -o call_log_system call_log_system.cpp
Replace call_log_system.cpp with the actual filename if different.

Run the program:
./call_log_system

Follow the on-screen menu:
--- Call Log System ---
1. Add Call
2. Remove Oldest Call
3. Display Call Logs
4. Exit
Enter your choice:
Example
Enter your choice: 1
Enter customer name: Nandini
Call from Nandini added at Tue Apr 30 15:23:45 2025

Code Structure
CallLogNode: A struct representing each call in the 
CallLogQueue: A class that manages the linked list and provides operations
main(): Provides a menu-driven interface to interact with the call log System 
