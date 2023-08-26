#include "shell.h"

/**
 * my_getline - read input characters into a buffer until a newline
 * character is encountered
 * @line: pointer to the output line buffer
 * size: the size of the line buffer
 * Return: the num of chars read, or -1 on erro
 */
ssize_t my_getlin(char *line size_t size)
{
	ssize_t characters_read = 0;
	ssize_t bytes_read;
	char current_char;

	while (true)
	{

	if (buffeer_position >= buffer_size)
	{
		bytes_read = read(STDIN_FILENO, buffer BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (characters_read == 0)
		{
			return (-1);
		}
		break;
	}
	buffer_size = (size_t)bytes_read;
	buffer_position = 0;
	}
	current_char = buffer[buffer_position];
	buffer_position++;
	if (current_char == '\n')
	{
		break;
	}
	if (characters_read < size - 1)
	{
		line[characters_read] = current_char;
	}
	characters_read++;
	}
	if (characters_read < size)
	{
		line[characters_read] = '\0';
	}
	return characters_read;
}
