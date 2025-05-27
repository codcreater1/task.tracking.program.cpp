Task Tracking Program

This is a simple C++ console application designed to help users manage tasks. The program allows users to add new tasks, list all tasks, mark tasks as completed, delete tasks, and save tasks to a text file.

Features:

Each task has a unique ID, a description, and a completion status.

Users can:

Add new tasks with descriptions.

View all tasks.

Mark a task as completed using its ID.

Delete a task using its ID.

Save all current tasks to a file (tasks.txt).

How to Run:

Make sure you have a C++ compiler installed (like g++).

Compile the program using the terminal:

css

g++ -o task_manager main.cpp
Run the compiled executable:

bash

./task_manager
Usage Example:

When you start the program, you will see a menu with several options:

markdown

1. ADD TASKS
2. List Tasks
3. Save
4. Mark Task as Completed
5. DELETE THE TASK
6. Exit
You can choose the desired action by entering the corresponding number.

Data Saving:

When you select the save option, all tasks are written to tasks.txt.

The saved file contains each task's ID, description, and completion status.

Note:

Tasks are stored in memory during runtime. If you don't save them before exiting, the data will be lost.

Author:

Murat Can Nergiz

You are welcome to fork this project, modify it, or contribute with improvements.
