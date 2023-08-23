#include "shell.h"
#include <errno.h>

/**
 * find_exe - This function searches for the executable in the PATH environment
 * variable.
 * @filename: name of the executable we are finding
 * Return: Executable's full path if found; NULL otherwise
 */
char *find_exe(const char *filename)
{
	char *path_var = getenv("PATH");
	char *path_copy = strdup(path_var);
	char *directory = strtok(path_copy, ":");
	char *exe_path = NULL;
	size_t exe_path_len;

	printf("Debug: PATH variable: %s\n", path_var);

	if (path_var == NULL)
	{
		printf("Debug: PATH environment variable is not set.\n");
		errno = EINVAL;
		return (NULL);
	}

	if (path_copy == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}

	while (directory != NULL)
	{
		printf("Debug: Current directory: %s\n", directory);
		exe_path_len = strlen(directory) + 1 + strlen(filename) + 1;
		exe_path = (char *)malloc(exe_path_len);

		if (exe_path == NULL)
		{
			perror("malloc error");
			free(path_copy);
			exit(EXIT_FAILURE);
		}

		snprintf(exe_path, exe_path_len, "%s/%s", directory, filename);

		printf("Debug: Constructed executable path: %s\n", exe_path);

		if (access(exe_path, X_OK) == 0)
		{
			free(path_copy);
			return (exe_path);
		}

		free(exe_path);
		directory = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
