#include "shell.h"

/**
 * builtin_handler - handles built
 * @cmd: tokenized commands
 * @input: input read
 *
 * Return: 1 on success, 0 otherwise
 */
int builtin_handler(char **cmd, char *input)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*cmd, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*cmd, builtin.exit) == 0)
	{
		exit_shell(cmd, input);
		return (1);
	}
	return (0);
}

