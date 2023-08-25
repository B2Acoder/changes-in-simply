3#include "shell.h"
/**
 * _stringlen - checks the length of a string
 * @s: checks string
 * REturn: length
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

/**
 * *_stringcat - concatenates two string
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
/**
 * *_stringchr -function locates a character in a string
 * @s: string
 * @c: character
 * Return: a pointer to the first occurrence of hte character c in the string s
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

/**
 * _stringspn - gets the length of prefix substring
 * @s:string
 * @accept: prefix to be measured
 * Return: the number of bytes in s which
 * consist only bytes  from accept
 */

unsigned int _stringspn(char *s, char *accept)
{
        unsigned int byteCount = 0;
        int acceptPos;

        while (*s)
        {
                for (accessPos = 0; accept[acceptPos]; acceptPos++)
                {
                        if (*s == accept[acceptPos])
                        {
                                byteCount++;
                                break;
                        }
                        else if (accept[acceptPos + 1] == '\0')
                                return (byteCount);
                }
                s++;
        }
        return (byteCount);
}
