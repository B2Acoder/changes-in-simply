#include "shell.h"

/**
 * execute_executable - This function forks a new process, using 'execve'
 *			to execute the provided executable path and waiting
 *				for the child process to complete.
 * @executable_path: The path to the executable
 * @args: The array of arguments for the executable
 * Return: (void)
 */
void execute_executable(char *executable_path, char **args)
{
	pid_t childprocess;
	int i;
	int status;

	is_process_running = 1;
	childprocess = fork();

	if (childprocess < 0)
	{
		perror("Fork error");
		free(executable_path);
		free_arguments(args);
		exit(EXIT_FAILURE);
	}

	else if (childprocess == 0)
	{
		if (execve(executable_path, args, environ) == -1)
		{
			perror("</3: execve error");
		}

		free(executable_path);
		free_arguments(args);
		exit(EXIT_FAILURE);
	}

	else
	{
		wait(&status);
	}

	printf("Debug: Executable path: %s\n", executable_path);
	printf("Debug: Arguments:\n");

	for (i = 0; args[i] != NULL; i++)
	{
		printf("  %d: %s\n", i, args[i]);
	}

	is_process_running = 0;
	free(executable_path);
	free_arguments(args);
}
