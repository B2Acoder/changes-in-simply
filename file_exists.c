#include "main.h"

/**
 * file_exists - This function checks if a file exists at a given path
 * @*p: Path
 * Return: A boolean value. True if the file exists and false otherwise
 */
bool file_exists(const char *p)
{
	struct stat buff;/*this struct stores infor about the file like size*/
	if (stat(p, &buff) == 0)
	{
		return True;/*means the file exits*/
	}
	else
	{
		return false;/*the files doesnot exit*/
	}
}
