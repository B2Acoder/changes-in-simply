#include "main.h"

int main(void)
{
	char *user_input = "ls -l";
	char **args = parse_args(user_readinput);
	execute_commandargs(user_input, args);
	return (0);
}
