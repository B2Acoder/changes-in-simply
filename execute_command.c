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
		if (execve(executable_path, args, NULL) == -1)
			/*replaces the current process with new process*/
		{
			perror("execve error for command: ");
			exit(EXIT_FAILURE);/*exits the pid with failure*/
		}
	}
	else/*executes in the ppid*/
	{
		waitpid(childprocess, &status, 0);
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
	char **arguments = tokenize_commandargs(command_path);

	if(arguments[0] != NULL)
	{
		execute_executable(arguments[0], arguments);
	}
	else
	{
		printf("No command provided\n");
	}
	for (index = 0; arguments[index] != NULL; index++)
	{
		free(arguments[index]);
	}
	free(arguments);
}
