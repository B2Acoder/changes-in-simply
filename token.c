#include "shell.h"

/**
 * tokenize_commandargs - this function tokenize a command
 * string into individual arguments
 * @command: input command stirng to be tokenized
 * Return: an array of arguments
 */
char **tokenize_commandargs(char *command)
{
	char **arguments = malloc(sizeof(char *) * (MAX_ARGS + 1));
	char *token = strtok(command, " ");
	/*tokenize the command stirng using space as the delimiter*/
	char argIndex = 0; /*initialize an index for the args array*/

	if (arguments == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while (token != NULL && argIndex < MAX_ARGS)
		/*the loop goes through the tokens*/
	{
		arguments[argIndex] = strdup(token);
		/*duplicates the token and stores it in the args array*/
		if (arguments[argIndex] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		argIndex++;/*ncrement the next index in the arg array*/
		token = strtok(NULL, " "); /*we get the next token in the command string*/
	}
	arguments[argIndex] = NULL; /*terminates the args array with NULL pointer*/
	return (arguments); /*returns the array of arguments*/
}

