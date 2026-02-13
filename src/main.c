#include <stdio.h>      // printf, perror
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>     // getcwd
#include <string.h>     // strcspn


int main(void){
    char cwd[1024];     // Buffer to store current working directory
    char command[1024]; // Buffer to store user input

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

    return EXIT_SUCCESS;
}