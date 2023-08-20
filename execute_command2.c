#include "main.h"

/**
 * execute_commandargs - this functions handles commands with args
 * @user_input - the user input contains commands followed by args
 * Return: void
 */

void execute_commandargs(char *user_input, char **args)
{

	if (args != NULL)
	{
		if (args[0] != NULL)
		{
			execute_commandargs(user_input, args);
		}
		else
		{
			printf("Error: No such command\n");
		}
	}
	else
	{
		printf("</3: No such file or directory\n");
	}
	free(args);
}

/* this funciton tokenizes the input string to separate the command and its args, allocates memory for an array to store the args, copies of the args into array and nullifies the array before it returns*/

/**
 * parse_args - this functions parsed the arguments from the user input
 * @user_input - user input that contains commands followed by arguments
 * Return: allocated array of arguments
 */

char **parse_args(char *user_input)
{
	int i;/*loop counter*/
	char *token = strtok(user_input, " ");/*iterator through the userinput stirng and tokenize*/
	char **args = malloc(sizeof(char *) * 2);

	while (token != NULL)
	{
		args[i] = token;
		i++;
		args = realloc(args, sizeof(char *) * (i + 2)); /**/
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
