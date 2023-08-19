#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

int prompt_design(void);
char *user_readinput(void);
void execute_executable(char *executable_path);
void execute_command(char *command_path);
bool file_exists(const char *p, struct stat *buff);
int prompt_loop(void);

#endif
