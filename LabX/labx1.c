/*
 * Exercise 1
 * 
 * Create a simple C program that forks 3 times and each fork() prints its PID
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    // We will print along the number of the child the parent PID to distinguish them
    
    if (pid == 0) {
        printf("Child 1-%d PID: %d\n", getppid(), getpid());
    }
    pid = fork();
    if (pid == 0) {
        printf("Child 2-%d PID: %d\n", getppid(), getpid());
    }
    pid = fork();
    if (pid == 0) {
        printf("Child 3-%d PID: %d\n", getppid(), getpid());
    }
}