#include "shell.h"

/**
 * user_readinput - This function reads user input.
 * @input_size: Argument
 * Return: input
 */
char *read_user_input(size_t *input_size)
{
	char *input_line = NULL;
	size_t read_size;

	read_size = getline(&input_line, input_size, stdin);

	if (read_size == (size_t)-1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	return (input_line);
}
