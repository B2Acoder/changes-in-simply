#include "shell.h"

/**
 * free_arguments - This function frees the memory allocated for an array
 * of arguments
 * @args: The array of arguments to be freed
 * Return: void
 */
void free_arguments(char **args)
{
	int index;

	if (args == NULL)
		return;

	for (index = 0; args[index] != NULL; index++)
	{
		free(args[index]);
	}
	free(args);
}
