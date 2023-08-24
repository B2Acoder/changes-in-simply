#include "shell.h"

/**
 * read_user_input - This function reads commands
 *
 * Return: command
 */
char *read_user_input(void)
{
	char *input = NULL;
	size_t buffersize = 0;

	if (getline(&input, &buffersize, stdin) == -1)
	{
		return (NULL);
	}

	return (input);
}
