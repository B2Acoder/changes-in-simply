#include "shell.h"

/**
* _strdup - dupicates string
* @s: to be duplicated
*
* Return: pointer to duplicate string
*/
char *_stringdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _stringlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}
