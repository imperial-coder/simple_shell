#include "shell.h"

/**
 * exit_shell - exit cmd
 * @cmd: tokenized command
 * @input: input read from stdin
 *
 * Return: void
 */
void exit_shell(char **cmd, char *input)
{
	free(input);
	free_buffers(cmd);
	exit(0);
}
