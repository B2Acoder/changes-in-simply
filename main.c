#include "shell.h"

/**
 * main - checks the code
 *
 * Return: Always 0
 */
volatile sig_atomic_t is_process_running = 0;

int main(void)
{
	signal(SIGINT, sigint_handler);

	prompt_loop();

	return (0);
}
