#include "shell.h"

/**
 * signint_handler - Signal handler function
 * @signum: Argument 1
 * Return: Void
 */
void sigint_handler(int __attribute__ ((unused)) signum)
{
	if (is_process_running)
	{
		printf("Ctrl+C pressed. Stopping the current process.\n");
	}
	else
	{
		printf("Ctrl+C pressed. Use 'exit' to quit the shell.\n");
		prompt_design();
	}
}
