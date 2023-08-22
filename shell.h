#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

int is_interactive_mode(void);
int prompt_design(void);
char *user_readinput(void);
char *read_fileinput(char *file_input);
void execute_executable(char *executable_path);
void execute_command(char *command_path);
bool file_exists(const char *p);
int prompt_loop(void);
char **parse_args(char *user_input);
void execute_commandargs(char *user_input, char **args);

#endif
