#include "shell.h"

/**
 * execute_command - This function executes a command entered by the user
 *
 * @command_path: The string representing the command
 * Return: void
 */
void execute_command(char *command_path)
{
    char **arguments = tokenize_commandargs(command_path);

    if (arguments == NULL || arguments[0] == NULL)
    {
        printf("</3: Empty command\n");
        return;
    }

    printf("Debug: Command to execute: %s\n", arguments[0]);

    if (strcmp(arguments[0], "exit") == 0)
    {
	    free_arguments(arguments);
	    shell_exit();
    }
    else if (strcmp(arguments[0], "env") == 0)
    {
        print_env();
    }
    else
    {
        char *executablepath = find_exe(arguments[0]);

        if (executablepath != NULL)
        {
            printf("Debug: Executable path to execute: %s\n", executablepath);
            execute_executable(executablepath, arguments);
            free(executablepath);
        }
        else
        {
            fprintf(stderr, "</3: %s: command not found\n", arguments[0]);
        }
    }

    free_arguments(arguments);
}
