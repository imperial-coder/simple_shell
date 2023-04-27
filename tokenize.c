#include "shell.h"

/**
 * tokenize - splits the inputs to tokens
 * @input: input from user
 *
 * Return: tokens
 */
char **tokenize(char *input)
{
	char *buffer = NULL;
	char *bufp = NULL, *token = NULL, *delimeter = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t idx = 0, flag = 0;

	buffer = _strdup(input);
	if (!buffer)
		return (NULL);

	bufp = buffer;

	while (*bufp)
	{
		if (_strchr(delimeter, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delimeter, *bufp) == NULL && flag == 1)
		flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buffer, delimeter);
	while (token)
	{
		tokens[idx] = _strdup(token);
		if (tokens[idx] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimeter);
		idx++;
	}
	tokens[idx] = '\0';
	free(buffer);

	return (tokens);
}
