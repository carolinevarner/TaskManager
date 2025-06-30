# Task Manager

A simple, interactive command-line task manager built in C. This project showcases file I/O, structs, sorting algorithms, memory management, modular code design, and user interaction in a C program.

---

## Features

- Add tasks with a name, due date, and priority
- View all tasks in a formatted list
- Delete tasks by number
- Sort tasks by priority (high → low)
- Persistent storage in `tasks.txt`
- Clean, modular code using header files
- ANSI-colored terminal interface 🎨

---

## Project Structure
  ```bash
  task_manager/
  ├── main.c # Main menu and logic
  ├── task.c # Functions for task management
  ├── task.h # Task struct and function declarations
  ├── tasks.txt # Automatically created/updated save file
  └── Makefile # For easy compilation
  ```

---

## How to Build and Run

1. **Clone or download** the repo:
   ```bash
   git clone https://github.com/yourusername/c-task-manager.git
   cd c-task-manager
   ```
2. Build using Makefile:
  ```bash 
  make
  ```
3. Run the program
  ```bash
  ./task_manager
  ```
4. (Optional) Clean up compiled files:
  ```bash
  make clean
  ```




