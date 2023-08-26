#include "shell.h"

int my_main()
{
	char line[BUFFER_SIZE];

	while (true)
	{
		printf("Enter a line: ");
		chars_read = my_getline(line, BUFFER_SIZE);
		if (chars_read == - 1)
		{
			printf("End of input.\n");
			break;
		}
		printf("You enterd: %s\n", line);
	}
	return (0);
}
