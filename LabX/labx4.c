/*
 * Exercise 4
 * 
 * Create a simple C program that has a parent and a child process and both processes write their PID to the same file
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork has failed\n");
        exit(1);
    }

    FILE *file = fopen("file.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fclose(file);

    if (pid == 0) {       
        sleep(1);
        FILE *file = fopen("file.txt", "a");
        printf("Child is writing to file\n");
        fprintf(file, "Child process with pid %d and parent %d\n", getpid(), getppid());
        fclose(file);
    } else {
        // parent
        FILE *file = fopen("file.txt", "a");
        printf("Parent is writing to file\n");
        fprintf(file, "Parent process %d\n", getpid());
        fclose(file);
        sleep(3);
    }

}
