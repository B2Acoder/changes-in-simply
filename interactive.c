#include "shell.h"

/**
 * handle_imode - this function handles signals for interactive mode
 * @sig_num: signal number
 *
 * Description: manages signals and keeps track of imode and prints
 * a prompt after receiving a signal
 * Return: void
 */

void handle_imode(int sig_num)
{
	(void)sig_num;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "<3", 2);
}
