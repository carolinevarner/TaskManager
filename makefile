# Makefile - automate compilation of the task manager project

CC = gcc
CFLAGS = -Wall          # Show all warnings
OBJS = main.o task.o    # Object files

# Build the executable
all: task_manager

task_manager: $(OBJS)
	$(CC) $(CFLAGS) -o task_manager $(OBJS)

main.o: main.c task.h
	$(CC) $(CFLAGS) -c main.c

task.o: task.c task.h
	$(CC) $(CFLAGS) -c task.c

# Clean build artifacts
clean:
	rm -f *.o task_manager
