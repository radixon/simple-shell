#include <stdio.h>      // printf, perror
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>     // getcwd
#include <string.h>     // strcspn
#include <stdbool.h>    // true


int main(void){
    const int KB = 1024;
    const int MAX_ARGS = 64;    // Maximum number of arguments for a command


    char cwd[KB];     // Buffer to store current working directory
    char command[KB]; // Buffer to store user input
    char *args[MAX_ARGS + 1];   // Add 1 for NULL terminator required by execve

    while(true){
        /*******  Display the prompt  ******/
        // getcwd returns NULL on error, otherwise getcwd returns a point to the buffer cwd[1024]
        if(getcwd(cwd, sizeof(cwd)) != NULL){
            printf("%s>", cwd);
        }
        else{
            perror("getcwd() error");   // System error message
            return EXIT_FAILURE;
        }


        /*******  Read command from user  ******/
        if(fgets(command, sizeof(command), stdin) != NULL){
            command[strcspn(command, "\n")] = 0;    // strcspn replaces first newline with null terminator due to fgets including newline character
            printf("Command entered: '%s'\n", command); // Print command to confirm the command was read correctly
        }
        else{
            printf("\nExiting Shell.\n");
            break;
        }

        /*  Remove Trailing newline character*/
        command[strcspn(command, "\n")] = 0;

        /*  --exit-- built-in command */
        if(strcmp(command, "exit") == 0){
            printf("Exiting Shell.\n");
            break;
        }

        /*  Parse command and arguments */
        if(strlen(command) == 0){ // --Enter-- pressed by user
            continue;
        }

        char *token;
        int i = 0;

        /*  Get first token  */
        token = strtok(command, " ");
        while(token != NULL && i < MAX_ARGS){
            args[i] = token;
            i++;
            // Get next token
            token = strtok(NULL, " ");
        }

        args[i] = NULL;     // exec functions require a NULL-terminated array of arguments

        /*  Print parsed command and arguments  */
        if(args[0] != NULL){
            printf("Commnad: '%s'\n", args[0]);
            for(int j=1; args[j] != NULL; j++){
                printf("Argument %d: '%s'\n", j, args[j]);
            }
        }
        else{
            printf("No command parsed.\n");
        }
    }
    

    return EXIT_SUCCESS;
}