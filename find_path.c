#include "shell.h"

/**
 * find_path_in_env - this function finds and return
 * the PATH environment variables
 *
 * Return: NULL if PATH is not found, or othrwise
 */
char *find_path_in_env(void)
{
	int char_index = 0;
	char **environment_variables = environ, *path_variable = NULL;

	while (*environment_variables)
	{
		if (_strncmp(*environment_variables, "PATH=", 5) == 0)
		{
			path_variable = *environment_variables;
			while (*path_variable && char_index < 5)
			{
				path_variable++;
				char_index++;
			}
			return (path_variable);
		}
		environment_variables++;
	}
	return (NULL);
}
