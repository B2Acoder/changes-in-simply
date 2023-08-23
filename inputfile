#include "shell.h"

/**
 * read_fileinput - This function reads a command from an input source when the
 * shell is running in non-interactive mode.
 * @file_input: File pointer
 * Return: command
 */
char *read_fileinput(FILE *file_input)
{
	size_t buffer_size = 0;
	char *command = NULL;
	ssize_t read_size;

	read_size = getline(&command, &buffer_size, file_input);

	if (read_size == -1)
	{
		free(command);
		return (NULL);
	}

	if (read_size > 0 && command[read_size - 1] == '\n')
	{
		command[read_size - 1] = '\0';
	}

	return (command);
}
