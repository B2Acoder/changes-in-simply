#include "shell.h"

/**
 * file_exists - This function checks if a file exists at a given path
 * @p: Path
 * Return: A boolean value. True if the file exists and false otherwise
 */
bool file_exists(const char *p)
{
	if (access(p, F_OK) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
