A simple, console-based to-do-list application written in c++. This project demonstrates core c++ principles and file I/O for data persistence.

## Features
- **Add, remove and view tasks:** Perform all basic to-do-list operations.
- **Mark task as complete:** Keep track of your progress.
- **Persistent storage:** Tasks are saved to `tasks.txt` and reloaded when application is restarted.
- **Multi-line descriptions:** Add detailed, multi-line descriptions to your tasks.

## Getting started
### Prerequisites
To build and run this project, you will need
- A C++20 compiler
- CMake (3.16 or later)

### Building the project
1. Clone the repositary and navigate to to repo directory
   
   ```
   git clone https://github.com/Nagul75/todoListManager.git
   cd todoListManager/
   ```
   
2. Configure and build with CMake:
   
   ```
   cmake .
   make
   ```
   
3. Run the application

   `./todoListManager`

## How to use

Upon launching the application, you will be presented with a menu of options. Select an option by typing the corresponding number and pressing Enter. Follow the on-screen prompts to manage your tasks.

## File Format

The tasks.txt file uses a custom format to store tasks, ensuring that multi-line descriptions are handled correctly. Each record is structured as follows and separated by ~~~:

1. Completion Status: 1 for complete, 0 for incomplete.
2. Task Name: A single line for the task's title.
3. Task Description: One or more lines for the full description.

End-of-Record Delimiter: The line ~~~ marks the end of a task.


   
