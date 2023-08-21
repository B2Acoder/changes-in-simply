#include "shell.h"

/**
 * main - checks the code
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char command_input[1024];/*stores the actual user input*/
	ssize_t read_size; /*keeps track of the number of chars read*/
	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt_loop();
		}
		else
		{
			char command_input[1024];
			ssize_t read_size;
		}
		while ((read_size = read(STDIN_FILENO, command_input, sizeof(command_input))) > 0)
		{
			write(STDOUT_FILENO, command_input, read_size);
		}
	}
	return (0);
}
