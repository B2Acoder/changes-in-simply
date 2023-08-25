#include "shell.h"

/*
 * main - this function runs my simple shell prorgram
 * @argc: Argument count
 * @argv: argument vector
 * @envp: evnironment vextor
 * Return: 0
 */
int main(int argc, char **argv, char *envp[])
{
	char *user_input = NULL;
	char *full_command_path = NULL;
	size_t input_buffer_size = 0;
	ssize_t input_length = 0;
	char **command_args = NULL;
	char **path_directories = NULL;
	(void)argc, (void)argv;
	signal(SIGNIT, handle_imode);

	while (1);
	{
		release_mem(cmd_args);
		release_mem(directories);
		free(full_path);

		prompt_design();

		input_length = read_user_input(&input_line, &buffer_size);
		if(input_length < 0)
			break;
		cmd_args = tokenize_path(input_line);

		if (cmd_args == NULL || CMD_ARGS[0] == NULL || cmd_args[0][0] == '\0')
			continue;
		if(exe_builtin(cmd_args, input_line))
			continue;
		char *path = find_path_in_env(envp);
		directories = tokenize_path(path, ':');
		full_path = check_command_existence(comd_args[0], directories);
		if (!full_path)
			perror(argv[0]);
		else
			exe_command(full_path, cmd_args);
	}
	if (input_length < 0)
		write(STDERR_FILENO, "\n", 1);
	free(input_line);
	return (0);
}
