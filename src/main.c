#include <stdio.h>      // printf, perror
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>     // getcwd
#include <string.h>     // strcspn
#include <stdbool.h>    // true


int main(void){
    const int kb = 1024;
    char cwd[kb];     // Buffer to store current working directory
    char command[kb]; // Buffer to store user input

    while(true){
        // getcwd returns NULL on error, otherwise getcwd returns a point to the buffer cwd[1024]
        if(getcwd(cwd, sizeof(cwd)) != NULL){
            printf("%s>", cwd);
        }
        else{
            perror("getcwd() error");   // System error message
            return EXIT_FAILURE;
        }


        // read one line from standard input
        if(fgets(command, sizeof(command), stdin) != NULL){
            command[strcspn(command, "\n")] = 0;    // strcspn replaces first newline with null terminator due to fgets including newline character
            printf("Command entered: '%s'\n", command); // Print command to confirm the command was read correctly
        }
        else{
            printf("\nNo input received. Exiting.\n");
        }

        // check for exit command
        if(strcmp(command, "exit") == 0){
            printf("---Exiting shell---\n");
            break;
        }
        else if(strcmp(command, "exit") > 0){
            printf("---Command Received: %s---\n", command);
        }
    }
    

    return EXIT_SUCCESS;
}