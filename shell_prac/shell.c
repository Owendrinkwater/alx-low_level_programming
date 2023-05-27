#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char *command;
    size_t bufsize = BUFFER_SIZE;

    while (1) {
        printf("#cisfun$ ");

        // Read the command line input
        command = (char *)malloc(bufsize * sizeof(char));
        if (command == NULL) {
            perror("malloc error");
            exit(EXIT_FAILURE);
        }

        if (getline(&command, &bufsize, stdin) == -1) {
            // Handle end-of-file condition
            printf("\n");
            break;
        }

        // Remove the newline character at the end of the command
        command[strcspn(command, "\n")] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process

            // Execute the command using execve
            char *argv[] = {command, NULL};
            if (execve(command, argv, NULL) == -1) {
                perror("execve error");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process

            // Wait for the child process to finish
            int status;
            waitpid(pid, &status, 0);
        }

        // Free the allocated memory
        free(command);
    }

    return 0;
}
