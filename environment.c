#include "shell.h"

/**
 * print_env - This function prints the current environment variables.
 * Return: Void
 */
void print_env(void)
{
	extern char **environ;
	char *envariable;
	char *value;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		envariable = environ[i];
		value = strchr(envariable, '=');

		if (value != NULL)
		{
			*value = '\0';
			value++;
			printf("%s=%s\n", envariable, value);
		}
	}
}
