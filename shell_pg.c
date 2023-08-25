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
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)argv;
	
	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_imode);
	
	while (1)
	{
		release_mem(command);
		release_mem(paths);
		free(pathcommand);
		prompt_design();
		linesize = getline(&line, &bufsize, stdin);
		
		if (linesize < 0)
			break;
		info.ln_count++;
		
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = tokenizer(line);
		
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		
		if (check_command_existence(command, line))
			continue;
		
		path = find_path_in_env();
		paths = tokenizer(path);
		pathcommand = test_path(paths, command[0]);
		
		if (!pathcommand)
			perror(argv[0]);
		else
			exe_command(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
