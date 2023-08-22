#include "shell.h"

/**
 * prompt_loop - This file loops the shell and handles the end-of-file
 *	condition
 * Return: Always 0 (Success)
 */
int prompt_loop(void)
{
	FILE *fileinput = fopen("input.txt", "r");
	char *f_input;

	while (1)
	{
		if (is_interactive_mode())
		{
			prompt_design();

			char *input = user_readinput();

			if (input == NULL)
			{
				printf("\n");
				break;
			}
			if (strlen(input) > 0)
			{
				execute_command(input);
			}

			free(input);
		}
		else
		{
			f_input = read_fileinput(fileinput);

			if (f_input == NULL)
			{
				printf("\n");
				break;
			}

			if (strlen(f_input) > 0)
			{
				execute_command(f_input);
			}
			fclose(fileinput);
			free(f_input);
		}
	}
}
