#include "shell.h"

/**
 * _stringcmp - function compares two strings
 * @s1: input value
 * @s2: input value
 * Return: void
 */
int _stringcmp(const char *s1, const char *s2)
{
	int index = 0;

	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (0);
}
