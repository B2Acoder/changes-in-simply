#include "shell.h"

/**
 * print_env - This function prints the current environment variables.
 * Return: Void
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
