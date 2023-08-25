#include "shell.h"

/**
 * prompt_design - This function displays the prompt and waits for the user
 *	to type in a command.
 * Return: Always 0.
 */
int prompt_design(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
	{
		flags.interactive = 1;
	}

	if (flags.interactive)
	{
		write(STDERR_FILENO, "<3 ", 3);
	}

	return (0);
}
