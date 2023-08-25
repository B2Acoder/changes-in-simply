#include "shell.h"
/**
 * check_command_existence - checks to see weather its a built in function
 *@cmd: tokenized user input
 *@buf: line drived fromgetline function
 *Return: 1 if cmd excuted 0 if cmd is not executed
 */
int check_command_existence(char **cmd, char *buf)
{
	if (exe_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		exe_command(cmd[0], cmd);
		return (1);
	}
	return (0);
}
