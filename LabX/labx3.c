/*
 * Exercise 3
 * 
 * Create a simple C program that has a parent and a child process and parent signals the other process via kill()
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#if !defined __USE_POSIX
    #define __USE_POSIX
#endif
#include <signal.h>

#include <unistd.h>

// Signal handler
void signalHandler(int signal) {
    printf("The Child received signal %d\n", signal);
}

int main() {
    pid_t pid;

    // Fork the child
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork has failed\n");
        return 1;
    }

    if (pid == 0) {
        // This is the child process
        if (signal(SIGUSR1, signalHandler) == SIG_ERR) {
            fprintf(stderr, "Error while registering the singal handler to SIGUSR1\n");
            exit(EXIT_FAILURE);
        }
        while (1) {
            pause();
        }
    } else {
        int count = 3;
        printf("The parent process will send three SIGUSR1 signals to the child process and finally a SIGKILL signal to terminate it\n\n");
        sleep(1);
        while (count > 0) {
            printf("Sending SIGUSR1 signal to the child process\n");
            kill(pid, SIGUSR1);
            sleep(1);
            count--;
        }
        printf("\nSending SIGKILL signal to the child process\n");
        kill(pid, SIGKILL);
    }
}
