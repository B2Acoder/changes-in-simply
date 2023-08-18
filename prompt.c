#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * prompt_design - This function displays the prompt and waits for the user
 *	to type in a command.
 * Return: Always 0.
 */
int prompt_design(void)
{
	char *prompt = "<3\n ";
	
	write(STDOUT_FILENO, prompt, 3);
	return (0);
}
