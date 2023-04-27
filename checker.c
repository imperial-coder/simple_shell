#include "shell.h"

/**
 * checker - checks
 * @cmd: tokens
 * @buffer: input
 *
 * Return: 0 on success
 */

int checker(char **cmd, char *buffer)
{
	if (builtin_handler(cmd, buffer))
		return (1);
	else if (**cmd == '/')
	{
		executor(cmd[0], cmd);
		return (1);
	}
	return (0);
}

