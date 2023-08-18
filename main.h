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
void execute_executable(const char *executable_path);
void execute_command(char *c);
bool file_exists(const char *p);
int prompt_loop(void);

#endif
