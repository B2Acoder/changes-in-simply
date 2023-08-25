#include "shell.h"

/**
 * _stringcat - concatenates two string
 * @dest: appends of the string
 * @src: appends of the string
 * Return: dest
 */

char *_stringcat(char *dest, char *src)
{
	int dest_index = 0;
	int src_index = 0;

	while (dest[dest_index] != '\0')
	{
		dest_index++;
	}
	while (src[src_index] != '\0')
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}
