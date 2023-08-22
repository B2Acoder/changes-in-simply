#include "shell.h"

/**
 * execute_commandargs - this function handles commands with args
 * @user_input - the user input contains commands followed by args
 * @args - an array of command arguments
 * Return: void
 */

void execute_commandargs(char *user_input, char **args)
{
	int j = 0;
	char *command = args[0];

	if (args != NULL && args[0] != NULL)
	{
		if (strcmp(command, "exit") == 0)/*we compare the command with other special commands*/
		{
			for (j = 0; args[j] != NULL; j++)
			{
				free(args[j]);
			}
			free(args);
			free(user_input);
			exit(0);
		}
		else if (strcmp(command, "cd") == 0)
		{
			if (args[1] != NULL)
			{
				if (chdir(args[1]) != 0)
				{
					perror("cd failed");
				}
			}
			else
			{
				fprintf(stderr, "Usage: cd <directory>\n");
			}
		}
		else
		{
			pid_t childprocess = fork();
			if (childprocess == 0)
			{
				if (execve(command, args, NULL) == -1)
				{
					perror("Command execution failed");
					exit(EXIT_FAILURE);
				}
			}
			else if (childprocess > 0)
			{
				wait(NULL);
			}
			else
			{
				perror("Fork failed");
			}
		}
	}

	for (j = 0; args[j] != NULL; j++)
	{
		free(args[j]);
	}
	free(args);
	free(user_input);
}

/* This function tokenizes the input string to separate the command and its args, allocates memory for an array to store the args, copies of the args into array and nullifies the array before it returns*/

/**
 * parse_args - this functions parsed the arguments from the user input
 * @user_input - user input that contains commands followed by arguments
 * Return: allocated array of arguments
 */

char **parse_args(char *user_input)
{
	int currentsize = MAX_ARGS;
	char **args = malloc(sizeof(char *) * currentsize);
	int arg_count = 0;
	char *token = strtok(user_input, " ");/*iterator through the userinput string and tokenize*/

	while (token != NULL)
	{
		if (arg_count >= currentsize)
		{
			currentsize *= 2;
			args = realloc(args, sizeof(char *) * currentsize);
		}
		
		args[arg_count] = strdup(token);
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	return (args);
}
