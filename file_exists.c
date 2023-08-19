#include "main.h"

/**
 * file_exists - This function checks if a file exists at a given path
 * @p: Path
 * @buff: This struct stores info about the file like size
 * Return: A boolean value. True if the file exists and false otherwise
 */
bool file_exists(const char *p, struct stat *buff)
{
	return (stat(p, buff) == 0);
}
