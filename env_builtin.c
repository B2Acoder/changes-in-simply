#include "shell.h"

/**
 * env_builtin - implements the env buit-in command
 */

void env_builtin(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _stringlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
