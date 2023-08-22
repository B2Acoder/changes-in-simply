#include "shell.h"

/**
 * user_readinput - This function reads user input.
 *
 * Return: input
 */
char *user_readinput(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;

	read_size = getline(&input, &input_size, stdin);

	if (read_size == -1)
	{
		free(input);
		return (NULL);
	}

	if (input[read_size - 1] == '\n')
	{
		input[read_size - 1] = '\0';
	}

	return (input);
}
