#include "shell.h"

/**
 * env_builtin - implements the env buit-in command
 */
void env_builtin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
