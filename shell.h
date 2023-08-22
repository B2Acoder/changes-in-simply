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
char *read_fileinput(FILE *file_input);
void execute_executable(char *executable_path, char **args);
void execute_command(char *command_path);
bool file_exists(const char *p);
int prompt_loop(void);
char **tokenize_commandargs(char *command);
char *find_exe(const char *filename);
void print_env(void);
void shell_exit(void);

#endif
