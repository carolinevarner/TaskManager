// task.h - setting the Task struct and related function prototypes

#ifndef TASK_H
#define TASK_H

// Task struct definition
typedef struct {
    char name[100];       // Task name
    char due_date[20];    // Due date in YYYY-MM-DD format
    int priority;         // Task priority (1-5)
} Task;

// Function declarations
void addTask(Task *tasks, int *taskCount);
void listTasks(Task *tasks, int taskCount);
void deleteTask(Task *tasks, int *taskCount);
void sortTasksByPriority(Task *tasks, int taskCount);
void saveTasks(Task *tasks, int taskCount, const char *filename);
void loadTasks(Task *tasks, int *taskCount, const char *filename);
void filterByPriority(Task *tasks, int taskCount, int priority);
void filterByDate(Task *tasks, int taskCount, const char *date);

#endif