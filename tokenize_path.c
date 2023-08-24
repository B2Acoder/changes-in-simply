#include "shell.h"

/**
 * tokenize_path - Tokenize the PATH environment variables
 *
 * @path: PATH environment variables
 * @directories: Array to store directories
 * Return: Number of directories
 */
int tokenize_path(char *path, char *directories[])
{
	int num_dirs = 0;
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		directories[num_dirs++] = token;
		token = strtok(NULL, ":");
	}

	return (num_dirs);
}
