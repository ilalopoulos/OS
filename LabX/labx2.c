/*
 * Exercise 2
 * 
 * Create a simple C program that has a parent and a child process and parent signals the other process via pipe()
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

# define BUFFER_SIZE 100 // Size of the message

int main() {
    pid_t pid;

    // Create a pipe
    int fd[2]; // index 0 - read end, index 1 - write end
    pipe(fd); // actually create the pipe

    // Fork the child
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork has failed\n");
        return 1;
    }

    if (pid == 0) {
        // This is the child process
        // To read from a pipe we must:
        // 1. Close the write end of the pipe
        // 2. Read from the pipe
        // 3. Close the read end of the pipe
        close(fd[1]);
        char messageReceived[32];
        read(fd[0], messageReceived, sizeof(messageReceived));
        printf("The Child received: %s\n", messageReceived);
        close(fd[0]);
    } else {
        // This is the parent process
        // To write to a pipe we must:
        // 1. Close the read end of the pipe
        // 2. Write to the pipe
        // 3. Close the write end of the pipe
        close(fd[0]);
        char messageSent[] = "Hello world";
        printf("The parent is sending: %s\n", messageSent);
        write(fd[1], messageSent, sizeof(messageSent));
        close(fd[1]);
    }
}
