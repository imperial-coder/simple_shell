#include "shell.h"

/**
 * executor - executes
 * @c: command
 * @cmd:array of pointers to commands
 *
 * Return: 0
 */
void executor(char *c, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(c);

	if (child_pid == 0)
	{
		execve(c, cmd, env);
		perror(c);
		free(c);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
