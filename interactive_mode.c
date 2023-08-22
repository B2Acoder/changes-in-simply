#include "shell.h"

/**
 * is_interactive_mode - This function checks whether the shell is running
 * in interactive mode.
 * Return: 1 if the shell is running in interactive mode
 * and 0 otherwise.
 */
int is_interactive_mode(void)
{
	return (isatty(0));
}
