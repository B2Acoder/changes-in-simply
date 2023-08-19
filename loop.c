#include "main.h"

/**
 * prompt_loop - This file loops the shell and handles the end-of-file
 *	condition
 * Return: Always 0 (Success)
 */
int prompt_loop(void)
{
	while (1)
	{
		prompt_design();

		char *input = user_readinput();

		if (input == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		execute_command(input);

		free(input);
	}

	return (0);
}
