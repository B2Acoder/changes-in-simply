#include "shell.h"

/**
 * execute_command - This function executes commands
 *
 * @command: Command to execute
 * Return: 0 (SUCCESS)
 */
int execute_command(char *command)
{
	pid_t childprocess;

	char *command_name = strtok(command, " ");
	char *full_path = check_command_existence(command_name);

	command[strcspn(command, "\n")] = '\0';

	childprocess = fork();

	if (childprocess < 0)
	{
		perror("fork");
	}

	else if (childprocess == 0)
	{
		if (full_path)
		{
			char *argv[MAX_ARGS];
			char *envp[] = {NULL};

			int argc = 0;
			char *token = strtok(command, " ");

			while (token != NULL && argc < MAX_ARGS - 1)
			{
				argv[argc++] = token;
				token = strtok(NULL, " ");
			}

			argv[argc] = NULL;

			if (execve(full_path, argv, envp) == -1)
			{
				perror("</3 ");
				exit(EXIT_FAILURE);
			}
		}

		else
		{
			printf("Command not found: %s\n", command_name);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		wait(NULL);
	}

	return (EXIT_SUCCESS);
}
