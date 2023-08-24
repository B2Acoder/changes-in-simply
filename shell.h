#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#define MAX_DIRS 100

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

int prompt_design(void);
char *read_user_input(void);
int execute_command(char *command);
int tokenize_path(char *path, char *directories[]);
char *create_full_path(char *directory, char *command);
char *check_command_existence(char *command);

#endif
