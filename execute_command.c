#include "shell.h"

/**
 * execute_executable - This function forks a new process, using 'execve'
 *			to execute the provided executable path and waiting
 *				for the child process to complete.
 * @executable_path: The path to the executable
 * Return: (void)
 */
void execute_executable(char *executable_path)
{
	pid_t childprocess; /*stores thes pid*/

	childprocess = fork(); /*creates a new process*/
	/*the pid starts executing*/
	if (childprocess < 0)/*checks the return value*/
	{
		perror("Fork error");
	}
	else if (childprocess == 0)/*the new process starts here*/
	{
		char *args[] = {executable_path, NULL};

		if (execve(executable_path, args, NULL) == -1)
			/*replaces the current process with new process*/
		{
			perror("</3 ");
			exit(EXIT_FAILURE);/*exits the pid with failure*/
		}
	}
	else/*executes in the ppid*/
	{
		wait(NULL);/*wait for the pid to complete*/
	}
}

/*this function check whether a file with that path exists*/

/**
 * execute_command - This function takes a command as input and checks if the
 *			command starts with "/"
 *
 * @command_path: The string representing the command
 * Return: void
 */
void execute_command(char *command_path)
{
	if (command_path[0] == '/')
		/*checks if the first char of the string is a forward slash*/
	{
		struct stat file_path;
		if (file_exists(command_path, &file_path))
		{
			execute_executable(command_path);
		}
	}

	else
	{
		printf("</3: No such file or directory\n");
	}
}
