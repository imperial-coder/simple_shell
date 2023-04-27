#include "shell.h"

/**
 * free_buffers - frees
 * @buffer: buffer to be freed
 *
 * Return: void
 */
void free_buffers(char **buffer)
{
	int i = 0;

	if (!buffer || buffer == NULL)
		return;

	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}

	free(buffer);
}
