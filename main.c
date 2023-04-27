#include "shell.h"

/**
 * main - starting point for the simple shell project
 * @ac: argument count
 * @av: argument vector
 * @envp: argumnet environment
 *
 * Return: 0 on success
 */

int main(int ac, char **av, char *envp[])
{
	char *input = NULL, *path_command = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t inputsize = 0;
	char **tokens = NULL, **paths = NULL;
	(void)envp, (void)av;

	if (ac < 1)
		return (-1);
	signal(SIGINT, signal_handler);
	while (1)
	{
		free_buffers(tokens);
		free_buffers(paths);
		free(path_command);
		prompt();
		inputsize = getline(&input, &bufsize, stdin);
		if (inputsize < 0)
			break;
		info.ln_count++;
		if (input[inputsize - 1] == '\n')
			input[inputsize - 1] = '\0';
		tokens = tokenize(input);
		if (tokens == NULL || *tokens == NULL || **tokens == '\0')
			continue;
		if (checker(tokens, input))
			continue;
		path = find_path();
		paths = tokenize(path);
		path_command = check_path(paths, tokens[0]);
		if (!path_command)
			perror(av[0]);
		else
			executor(path_command, tokens);
	}
	if (inputsize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(input);
	return (0);
}
