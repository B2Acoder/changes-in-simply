#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#define MAX_DIRS 100
#define NUM_BUILTIN_CMNDS 3

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
int tokenize_path(char *path, char delimiter);
char *create_full_path(char *directory, char *command);
char *check_command_existence(char *command);
void env_builtin(void);
char *build_full_cmnd(char *p, char cmd);
int exe_builtin(char **cmd_args, char *input_line);
void exe_command(char *cmd_path, char **cmd_args);
char *find_path_in_en(void);
int _stringlen(char *s);
char *_stringcat(char *dest, char *src);
int _stringcmp(const char *s1, const char *s2);
char *_stringchr(char *s, char c);
unsigned int _stringspn(char *s, char *accept);
void handle_imode(int sig_num);
void release_mem(char ** memory_buff);
void shell_exit(void);
int main(int argc, char **argv, char *envp[]);


#endif
