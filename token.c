#include "shell.h"

/**
 * tokenize_commandargs - this function tokenize a command
 * string into individual arguments
 * @command: input command stirng to be tokenized
 * Return: an array of arguments
 */
char **tokenize_commandargs(char *command)
{
	 int bufsize = MAX_ARGS;
	 int position = 0;
	 char **tokens = malloc(bufsize * sizeof(char*));
	 char *token;

	 if (!tokens)
	 {
		 perror("malloc error");
		 exit(EXIT_FAILURE);
	 }

	 token = strtok(command, " \t\n\r\a");

	 while (token != NULL)
	 {
		 printf("Debug: Token found: %s\n", token);
		 tokens[position] = token;
		 position++;

		 if (position >= bufsize)
		 {
			 bufsize += MAX_ARGS;
			 tokens = realloc(tokens, bufsize * sizeof(char*));
			 if (!tokens)
			 {
				 perror("realloc error");
				 exit(EXIT_FAILURE);
			 }
		 }

		 token = strtok(NULL, " \t\n\r\a");
	 }

	 tokens[position] = NULL;

	 return (tokens);
}
