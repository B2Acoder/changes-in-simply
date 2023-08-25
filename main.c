#include "shell.h"

/**
 * main - checks the code
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt_design();
		command = read_user_input();

		if (command == NULL)
		{
			printf("\n");
			break;
		}

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}
		if (execute_command(command) != 0)
		{
			printf("Error executing command: %s\n", command);
		}
		free(command);
	}

	return (EXIT_SUCCESS);
}
