#include "shell.h"

/**
 * execute_executable - This function forks a new process, using 'execve'
 *			to execute the provided executable path and waiting
 *				for the child process to complete.
 * @executable_path: The path to the executable
 * @args: 
 * Return: (void)
 */
void execute_executable(char *executable_path, char **args)
{
	int status;
	extern char **environ;
	pid_t childprocess; /*stores thes pid*/

	childprocess = fork(); /*creates a new process*/
	/*the pid starts executing*/
	if (childprocess < 0)/*checks the return value*/
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (childprocess == 0)/*the new process starts here*/
	{
		execve(executable_path, args, environ);
		perror("</3: ");
		exit(EXIT_FAILURE);
	}
	else/*executes in the ppid*/
	{
		wait(&status);
	}
}

/**
 * execute_command - This function executes command entered by the user
 *
 * @command_path: The string representing the command
 * Return: void
 */
void execute_command(char *command_path)
{
	int index;
	char *executablepath;
	char **arguments = tokenize_commandargs(command_path);
	char *args = arguments[0];

	if (strcmp(args, "exit") == 0)
	{
		shell_exit();
	}
	else if (strcmp(args, "env") == 0)
	{
		print_env();
	}
	else
	{
		executablepath = find_exe(args);

		if (executablepath != NULL)
		{
			execute_executable(executablepath, arguments);
			free(executablepath);
		}
		else
		{
			printf("</3: %s: command not found\n", args);
		}
	}

	for (index = 0; arguments[index] != NULL; index++)
	{
		free(arguments[index]);
	}
	free(arguments);
}
