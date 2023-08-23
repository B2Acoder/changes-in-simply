#include "shell.h"

/**
 * prompt_loop - Loops the function
 * Return: 0
 */
int prompt_loop(void)
{
	char *input_line;
	char **arguments;
	size_t input_size = 0;

	while (1)
	{
		prompt_design();

		input_line = read_user_input(&input_size);

		 arguments = tokenize_commandargs(input_line);

		 if (arguments != NULL && arguments[0] != NULL)
		 {
			 execute_command(arguments[0]);
		 }

		 free(input_line);
		 free_arguments(arguments);
	}

	return (EXIT_SUCCESS);
}
