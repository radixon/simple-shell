#include <stdio.h>      // printf, perror
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>     // getcwd


int main(void){
    char cwd[1024];     // Buffer to store current working directory

    // getcwd returns NULL on error, otherwise getcwd returns a point to the buffer cwd[1024]
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        printf("Current Working Directory: %s\n", cwd);
        return EXIT_SUCCESS;
    }
    else{
        perror("getcwd() error");   // System error message
        return EXIT_FAILURE;
    }
}