#include "shell.h"

/**
 * build_full_cmnd - this function combines a path and a command
 * @p: the path to be combined
 * @cmd: the command to be combined
 * Return: A buffer that contains the combines path and command
 * on success and NULL on failure
 */
char *build_full_cmnd(char *p, char *cmd)
{
	char *result_buffer;
	size_t result_size;
	size_t path_index = 0, command_index = 0;

	if (cmd == 0)
		cmd = "";
	if (p == 0)
		p = "";
	result_size = _stringlen(p) + _stringlen(cmd) + 2;

	result_buffer = malloc(sizeof(char) * result_size);

	if (!result_buffer)
		return NULL;
	while (p[path_index])
	{
		result_buffer[path_index] = p[path_index];
		path_index++;
	}

	while (cmd[command_index])
	{
		result_buffer[path_index + command_index] = cmd[command_index];
		command_index++;
	}

	result_buffer[path_index + command_index] = '\0';

	return (result_buffer);
}
