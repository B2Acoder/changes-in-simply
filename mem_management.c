#include "shell.h"

/**
 * release_mem - this function releases dynamically
 * allocated memory for a buffer
 * @memory_buff: the buff to be deallocated
 */
void release_mem(char ** memory_buff)
{
	int index = 0;

	if (!memory_buff || memory_buff == NULL)
		return;
	while (memory_buff[index])
	{
		free(memory_buff[index]);
		index++;
	}
	free(memory_buff);
}
