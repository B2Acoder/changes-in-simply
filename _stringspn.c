#include "shell.h"

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
                for (acceptPos = 0; accept[acceptPos]; acceptPos++)
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
