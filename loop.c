#include "shell.h"

/**
 * prompt_loop - This file loops the shell and handles the end-of-file
 *	condition
 * Return: Always 0 (Success)
 */
int prompt_loop(void)
{
	int k = 0;

	while (1)
	{
		prompt_design();

		char *input = user_readinput();

		if (input == NULL)
		{
			printf("\n");
			break;
		}

		char **args = parse_args(input);

		if (args != NULL && args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				execute_commandargs(input, args);
			}
			else if(strcmp(args[0], "cd") == 0)
			{
				execute_commandargs(input, args);
			}
			else
			{
				execute_command(input);
			}
		}

		for (k = 0; args[k] != NULL; k++)
		{
			free(args[k]);
		}

		free(args);
		free(input);
	}
	
	return (0);
}
