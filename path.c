#include "shell.h"

/**
 * find_exe - This function searches for the executable in the PATH environment
 * variable.
 * @filename: name of the executable we are finding
 * Return: Executable's full path if found; NULL otherwise
 */
char *find_exe(const char *filename)
{
	char *path;
	char *directory;
	char *exe_path;

	path = getenv("PATH");
	directory = strtok(path, ":");
	exe_path = NULL;

	while (directory != NULL)
	{
		exe_path = malloc(strlen(directory) + strlen(filename) + 2);
		sprintf(exe_path, "%s%s", directory, filename);

		if (access(filename, X_OK) == 0)
		{
			return (exe_path);
		}

		free(exe_path);
		directory = strtok(NULL, ":");
	}

	return (NULL);
}
