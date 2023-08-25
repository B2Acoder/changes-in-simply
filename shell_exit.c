#include "shell.h"

/**
 * shell_exit - This function exits the shell
 * @cmd: tokenized command
 * @inputline: input read from stdin
 *
 * Return: void
 */

void shell_exit(char **cmd, char *inputline)
{
	free(inputline);
	release_mem(cmd);
	exit(0);
}
