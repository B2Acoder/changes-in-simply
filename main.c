#include "shell.h"

/**
 * main - checks the code
 * @argc - argument count
 * @argv - array of strings representing tthe args
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	/*arrays holds the command and arguments enterd by the user*/
	char command_input[1024];/*stores the actual user input*/
	ssize_t read_size; /*keeps track of the number of chars read*/
	if (argc == 1)/*checks if there are no command line args provided when running the program*/
	{
		if (isatty(STDIN_FILENO))/*checks if the programs runs in an interactive terminal*/
		{
			prompt_loop();/*if it runs interactivey it calls prompt loop*/
		}
		else/*if its not running interactively like reading input ffrom a file then*/
		{
			command_input[1024];
			read_size;
		}
		while ((read_size = read(STDIN_FILENO, command_input, sizeof(command_input))) > 0)/* reads input from standard input using the read function*/
		{
			write(STDOUT_FILENO, command_input, read_size);/*writes the content of command input to stdout*/
		}
	}
	return (0);
}
