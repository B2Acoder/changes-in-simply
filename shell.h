#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 1024
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
#include <time.h>
#include <stdarg.h>

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

struct info
{
	int final_exit;/*stores the programs exit status*/
	int ln_count;/*keeps track of line counts*/
} info;

struct flags
{
	bool interactive;
} flags;

int prompt_design(void);
char *read_user_input(void);
char **tokenize_path(char *path, char delimiter);
char *create_full_path(char *directory, char *command);
int check_command_existence(char **cmd, char *buf);
void env_builtin(void);
char *build_full_cmnd(char *p, char *cmd);
int exe_builtin(char **cmd_args, char *input_line);
void exe_command(char *cmd_path, char **cmd_args);
char *find_path_in_env(void);
int _stringlen(char *s);
char *_stringcat(char *dest, char *src);
int _stringcmp(const char *s1, const char *s2);
char *_stringchr(char *s, char c);
unsigned int _stringspn(char *s, char *accept);
int _strncmp(char *s1, char *s2, int n);
char *_stringdup(char *s);
void handle_imode(int sig_num);
void release_mem(char **memory_buff);
void shell_exit(char **cmd, char *inputline);
int main(int argc, char **argv, char *envp[]);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
ssize_t my_getline(char *line, size_t size);
#endif
