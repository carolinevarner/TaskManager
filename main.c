#include <stdio.h>
#include <stdlib.h>
#include "task.h"

#define MAX_TASKS 100
#define FILENAME "tasks.txt"

int main() {
    Task tasks[MAX_TASKS];      // Array to hold tasks
    int taskCount = 0;          // Number of tasks currently in memory
    int choice;                 // Menu selection

    loadTasks(tasks, &taskCount, FILENAME); // Load saved tasks from file (if any)

    // Main menu loop
    do {
        printf("\n--- Task Manager ---\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Sort Tasks by Priority\n");
        printf("5. Save and Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline after number input

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                listTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                sortTasksByPriority(tasks, taskCount);
                break;
            case 5:
                saveTasks(tasks, taskCount, FILENAME);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 5);  

    return 0;
}
