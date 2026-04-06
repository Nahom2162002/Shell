#ifndef SHELL_COMMANDS
#define SHELL_COMMANDS

void builtin_cd(char** args);

void builtin_pwd();

void builtin_exit();

void cat(char** args);

void echo(char** args);

void ls(char** args);

#endif 