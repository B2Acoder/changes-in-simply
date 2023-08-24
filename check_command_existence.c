#include "shell.h"

/**
 * check_command_existence - Check if a command exists in PATH
 *
 * @command: Command to check
 * Return: 1 if exists, 0 otherwise
 */
char *check_command_existence(char *command)
{
    int index = 0;
    char *path = getenv("PATH");
    char *directories[MAX_DIRS];
    int num_dirs = tokenize_path(path, directories);

    for (index = 0; index < num_dirs; index++)
    {
        char *full_path = create_full_path(directories[index], command);
        if (access(full_path, X_OK) == 0)
        {
            return full_path;
        }
    }
    return NULL;
}
