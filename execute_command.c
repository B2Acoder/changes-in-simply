#include "main.h"

/**
 * execute_executable - This function forks a new process, using 'execve'
 *			to execute the provided executable path and waiting
 *				for the child process to complete.
 * @*executable_path: The path to the executable
 * Return: (void)
 */
void execute_executable(const char *executable_path)
{
	pid_t child;

	child = fork();
	
	if (child < 0)
	{
		perror("Fork error");
	}
	else if (child == 0)
	{
		extern char **environ;
		char *args[] = {(char *)executable_path, NULL};
		if (execve(executable_path, args, environ) == -1)
		{
			perror("</3 ");
			exit(EXIT_FAILURE);
		}

		else
		{
			wait(NULL);
		}
	}
}

/**
 * execute_command - This function takes a command as input and checks if the
 *			command starts with "/"
 *
 * @*c: The string representing the command
 * Return: void
 */
void execute_command(char *c)
{
	if (c[0] == '/' && file_exists(c))
	{
		execute_executable(c);
	}
	else
	{
		printf("</3: No such file or directory\n");
	}
}
