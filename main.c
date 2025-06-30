#include <stdio.h>
#include <stdlib.h>
#include "task.h"

#define MAX_TASKS 100
#define FILENAME "tasks.txt"

// ANSI colors
#define RESET   "\x1b[0m"
#define YELLOW  "\x1b[33m"
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RED     "\x1b[31m"
#define MAGENTA "\x1b[35m"

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    loadTasks(tasks, &taskCount, FILENAME);

    do {
        printf("\n%s--- Task Manager ---%s\n", YELLOW, RESET);
        printf("%s1.%s Add Task\n", CYAN, RESET);
        printf("%s2.%s List Tasks\n", CYAN, RESET);
        printf("%s3.%s Delete Task\n", CYAN, RESET);
        printf("%s4.%s Sort Tasks by Priority\n", CYAN, RESET);
        printf("%s5.%s Filter by Priority\n", CYAN, RESET);
        printf("%s6.%s Filter by Date\n", CYAN, RESET);
        printf("%s7.%s Save and Exit\n", CYAN, RESET);
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addTask(tasks, &taskCount); break;
            case 2: listTasks(tasks, taskCount); break;
            case 3: deleteTask(tasks, &taskCount); break;
            case 4: sortTasksByPriority(tasks, taskCount); break;
            case 5: {
                int p;
                printf("Enter priority (1–5): ");
                scanf("%d", &p); getchar();
                filterByPriority(tasks, taskCount, p);
                break;
            }
            case 6: {
                char date[20];
                printf("Enter date to filter (YYYY-MM-DD): ");
                fgets(date, 20, stdin);
                date[strcspn(date, "\n")] = 0;
                filterByDate(tasks, taskCount, date);
                break;
            }
            case 7:
                saveTasks(tasks, taskCount, FILENAME);
                printf("Goodbye!\n");
                break;
            default: printf("Invalid option.\n");
        }

    } while (choice != 7);

    return 0;
}
