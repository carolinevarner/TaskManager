// task.c - implements functions for managing tasks

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "task.h"

// Validate date format: YYYY-MM-DD
int isValidDate(const char *date) {
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return 0;
    }
    return 1;
}

// Add a task to the list
void addTask(Task *tasks, int *taskCount) {
    printf("Enter task name: ");
    fgets(tasks[*taskCount].name, 100, stdin);
    tasks[*taskCount].name[strcspn(tasks[*taskCount].name, "\n")] = 0;

    do {
        printf("Enter due date (YYYY-MM-DD): ");
        fgets(tasks[*taskCount].due_date, 20, stdin);
        tasks[*taskCount].due_date[strcspn(tasks[*taskCount].due_date, "\n")] = 0;

        if (!isValidDate(tasks[*taskCount].due_date)) {
            printf("Invalid date format. Try again.\n");
        }
    } while (!isValidDate(tasks[*taskCount].due_date));

    printf("Enter priority (1–5): ");
    scanf("%d", &tasks[*taskCount].priority);
    getchar();

    (*taskCount)++;
    printf("Task added.\n");
}

// Display all tasks
void listTasks(Task *tasks, int taskCount) {
    printf("\n\x1b[33m--- Task List ---\x1b[0m\n");
    for (int i = 0; i < taskCount; i++) {
        printf("\x1b[35m%d.\x1b[0m %s | Due: %s | Priority: %d\n",
               i + 1, tasks[i].name, tasks[i].due_date, tasks[i].priority);
    }
    if (taskCount == 0)
        printf("No tasks yet.\n");
}

// Remove a task by index
void deleteTask(Task *tasks, int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    listTasks(tasks, *taskCount);
    printf("Enter task number to delete: ");
    int index;
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = index - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*taskCount)--;
    printf("Task %d deleted.\n", index);
}

// Sort tasks by priority descending
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

// Save tasks to a file
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

// Load tasks from file
void loadTasks(Task *tasks, int *taskCount, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    while (fscanf(fp, "%99[^;];%19[^;];%d\n",
                  tasks[*taskCount].name,
                  tasks[*taskCount].due_date,
                  &tasks[*taskCount].priority) == 3) {
        (*taskCount)++;
    }
    fclose(fp);
}

// Filter tasks by priority
void filterByPriority(Task *tasks, int taskCount, int priority) {
    printf("\nTasks with priority %d:\n", priority);
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].priority == priority) {
            printf("- %s | Due: %s\n", tasks[i].name, tasks[i].due_date);
            found = 1;
        }
    }
    if (!found) printf("No tasks with that priority.\n");
}

// Filter tasks by exact due date
void filterByDate(Task *tasks, int taskCount, const char *date) {
    printf("\nTasks due on %s:\n", date);
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].due_date, date) == 0) {
            printf("- %s | Priority: %d\n", tasks[i].name, tasks[i].priority);
            found = 1;
        }
    }
    if (!found) printf("No tasks with that date.\n");
}
