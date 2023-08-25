#include "shell.h"

/**
 * exe_command - this functions executes commands enterd by users
 * @cmd_path: the path to the command to be executed
 * @cmd_args: an array of command and its args
 * REturn: void
 */
void exe_command(char *cmd_path, char **cmd_args)
{
	pid_t childprocess_pid;
	int child_status;
	char **environment_var = environ;

	childprocess_pid = fork();

	if (childprocess_pid < 0)
	{
		perror("fork")
	}
	if (childprocess_pid == 0)
	{
		execve(cmd_path, cmd_args, environment_ar);
		perror("execve");

		free(cmd_paths);
		free_cmd_args(cmd_args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&child_status);
	}
}

