#include "shell.h"

/**
 * create_full_path - Create the full path for a command
 *
 * @directory: Directory in which the command should be
 * @command: Command
 * Return: Full path
 */
char *create_full_path(char *directory, char *command)
{
    size_t fullpath_len = strlen(directory) + strlen(command) + 2;
    char *fullpath = malloc(fullpath_len);

    if (fullpath == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    snprintf(fullpath, fullpath_len, "%s/%s", directory, command);

    return fullpath;
}
