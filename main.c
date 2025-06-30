#include <stdio.h>
#include <stdlib.h>
#include "task.h"

#define MAX_TASKS 100
#define FILENAME "tasks.txt"

#define RESET   "\x1b[0m"
#define YELLOW  "\x1b[33m"
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RED     "\x1b[31m"
#define MAGENTA "\x1b[35m"

int main() {
    Task tasks[MAX_TASKS];      // Array to hold tasks
    int taskCount = 0;          // Number of tasks currently in memory
    int choice;                 // Menu selection

    loadTasks(tasks, &taskCount, FILENAME); // Load saved tasks from file (if any)

    // Main menu loop
    do {
        printf("\n%s--- Task Manager ---\n%s", YELLOW, RESET);
        printf("%s1.%s Add Task\n", CYAN, RESET);
        printf("%s2.%s List Tasks\n", CYAN, RESET);
        printf("%s3.%s Delete Task\n", CYAN, RESET);
        printf("%s4.%s Sort Tasks by Priority\n", CYAN, RESET);
        printf("%s5.%s Save and Exit\n", CYAN, RESET);
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
