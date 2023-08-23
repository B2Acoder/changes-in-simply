#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

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
#include <signal.h>

extern volatile sig_atomic_t is_process_running;
extern char **environ;

int is_interactive_mode(void);
int prompt_design(void);
char *read_user_input(size_t *input_size);
char *read_fileinput(FILE *file_input);
void execute_executable(char *executable_path, char **args);
void execute_command(char *command_path);
bool file_exists(const char *p);
int prompt_loop(void);
void process_user_input(void);
void process_file_input(FILE *fileinput);
char **tokenize_commandargs(char *command);
char *find_exe(const char *filename);
void print_env(void);
void shell_exit(void);
void free_arguments(char **args);
void sigint_handler(int __attribute__((unused)) signum);

#endif
