// task.c - implements functions for managing tasks

#include <stdio.h>
#include <string.h>
#include "task.h"

// Add a new task to the task array
void addTask(Task *tasks, int *taskCount) {
    printf("Enter task name: ");
    fgets(tasks[*taskCount].name, 100, stdin);  // Read task name
    tasks[*taskCount].name[strcspn(tasks[*taskCount].name, "\n")] = 0; // Remove newline

    printf("Enter due date (e.g., 2025-07-01): ");
    fgets(tasks[*taskCount].due_date, 20, stdin); // Read due date
    tasks[*taskCount].due_date[strcspn(tasks[*taskCount].due_date, "\n")] = 0;

    printf("Enter priority (1–5): ");
    scanf("%d", &tasks[*taskCount].priority);  // Read priority
    getchar(); //  leftover newline

    (*taskCount)++;  // Increment task count
    printf("Task added.\n");
}

// List tasks in the array
void listTasks(Task *tasks, int taskCount) {
    printf("\n--- Task List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s | Due: %s | Priority: %d\n",
               i + 1, tasks[i].name, tasks[i].due_date, tasks[i].priority);
    }
    if (taskCount == 0)
        printf("No tasks yet.\n");
}

// Delete task by shifting the array to overwrite it
void deleteTask(Task *tasks, int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    listTasks(tasks, *taskCount);  // Show task
    printf("Enter task number to delete: ");
    int index;
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    // Shift all tasks after the deleted one up
    for (int i = index - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*taskCount)--;  // Decrease task count
    printf("Task %d deleted.\n", index);
}

// Sort tasks in-place from highest to lowest priority
void sortTasksByPriority(Task *tasks, int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = i + 1; j < taskCount; j++) {
            if (tasks[j].priority > tasks[i].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    printf("Tasks sorted by priority (high to low).\n");
}

// Save all tasks to a file 
void saveTasks(Task *tasks, int taskCount, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error saving file");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        fprintf(fp, "%s;%s;%d\n", tasks[i].name, tasks[i].due_date, tasks[i].priority);
    }
    fclose(fp);
    printf("Tasks saved to %s\n", filename);
}

// Load tasks from file if it exists (If file doesn't exist, skip loading)
void loadTasks(Task *tasks, int *taskCount, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return; 

    // fscanf format: read up to ; or newline for each field
    while (fscanf(fp, "%99[^;];%19[^;];%d\n",
           tasks[*taskCount].name,
           tasks[*taskCount].due_date,
           &tasks[*taskCount].priority) == 3) {
        (*taskCount)++;
    }

    fclose(fp);
}
