#include "shell.h"

/**
 * exe_builtin - this functions executes builtins commands
 * @cmd_args: this is the tokenized cmds
 * @input_line: this inputs read from stdin
 * Return: 1 if builtin command is executed and 0 if otherwise
 */
int exe_builtin(char **cmd_args, char *input_line)
{
	char *builtin_cmnds[NUM_BUILTIN_CMNDS] = {"env", "exit"};
	int command_i;

	for (command_i = 0; command_i < NUM_BUILTIN_CMNDS; command_i++)
	{
		if (_stringcmp(*cmd_args, builtin_cmnds[command_i]) == 0)
		{
			if (command_i == 0)
			{
				env_builtin();
			}
			else if (command_i == 1)
			{
				shell_exit(cmd_args, input_line);
			}
			return (1);
		}
	}
	return (0);
}
