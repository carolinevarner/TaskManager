// task.h - setting the Task struct and related function prototypes

#ifndef TASK_H
#define TASK_H

// Define a structure to represent the tasks
typedef struct {
    char name[100];       // Task name
    char due_date[20];    // Due date string (e.g., "2025-07-01")
    int priority;         // Priority level (1–5)
} Task;

// Declare Functions to be used
void addTask(Task *tasks, int *taskCount);                         // Add tasks
void listTasks(Task *tasks, int taskCount);                        // Display tasks
void deleteTask(Task *tasks, int *taskCount);                      // Delete tasks
void sortTasksByPriority(Task *tasks, int taskCount);              // Sort tasks (by priority)
void saveTasks(Task *tasks, int taskCount, const char *filename);  // Save tasks to a file
void loadTasks(Task *tasks, int *taskCount, const char *filename); // Load tasks from a file

#endif
