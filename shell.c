#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int main(char** args) {
    printf("Welcome to this custom based UNIX Shell that I made! This is just the beginning so as time passes there will certainly be updates.\n");
    printf("~$");
    char * command;

    while (fgets(command, sizeof(command), stdin)) {

    }
}

void builtin_cd(char** args) {
    if (args[1] == NULL) {
        char* home = getenv("HOME");
        if (chdir(home) != 0) {
            perror("cd");
        }
    }
    else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
}

void builtin_pwd() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    }
    else {
        perror("pwd");
    }
}

void builtin_exit(char** args) {
    if (args[1] != NULL) {
        exit(atoi(args[1]));
    }
    else {
        exit(0); 
    }
}

void cat(char** args) {

}

void echo(char** args) {

}

void ls(char** args) {
    pid_t pid;
    char* arguments[2] = { "ls", NULL };

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execvp(arguments[0], arguments);
        exit(EXIT_SUCCESS);
    }
}