#include "shell.h"

/**
 * _stringlen - checks the length of a string
 * @s: checks string
 * Return: length
 */
int _stringlen(char *s)
{
	int string_len = 0;
	while (*s != '\0')
	{
		string_len++;
		s++;
	}
	return (string_len);
}
