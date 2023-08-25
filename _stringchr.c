#include "shell.h"

/**
 * *_stringchr -function locates a character in a string
 * @s: string
 * @c: character
 * Return: a pointer to the first occurrence of the character c in the string
 * null if the character is not found
 */

char *_stringchr(char *s, char c)
{
	int current_position;

	for (current_position = 0; s[current_position] >= '\0'; current_position++)
	{
		if (s[current_position] == c)
			return (s + current_position);
	}
	return ('\0');
}
