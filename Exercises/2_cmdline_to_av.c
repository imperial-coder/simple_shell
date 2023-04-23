#include <stdio.h>
#include <string.h>

/* defining the maximum number of tokens */
#define MAX_NUM_OF_TOKEN 1024

/**
 * main - prints "$ ", wait for the user to enter a command,
 * prints it on the next line, tokenize the string adn returns an array
 * of each word of the string
 *
 * Return: 0 on success
 */
int main(void)
{
	char *lineptr;
	size_t n = 0;
	char *prompt = "$ ";
	ssize_t num_char_read;
	char *tokens[MAX_NUM_OF_TOKEN];
	int index = 0;

	/* creating an infinte loop that only exits when an EOF is enindexere */
	while (1)
	{
		/* printing out the prompt */
		printf("%s", prompt);

		/* getting user input */
		num_char_read = getline(&lineptr, &n, stdin);

		/* checking if getline fails or a case of EOF */
		if (num_char_read == -1)
			return (-1);

		/* printing the user input */
		printf("%s", lineptr);

		/* tokenizing the user input using the strtok function */
		/* first call of strtok (that is first tokenization) */
		tokens[index] = strtok(lineptr, " ");

		/* continous call to strtok until last command is tokenised or maximum value of token is maxed ou */
		while (tokens[index] && index < MAX_NUM_OF_TOKEN)
		{
			index++;
			tokens[index] = strtok(NULL, " ");
		}
		tokens[index] = NULL;

		/* printing the tokenise commands */
		index = 0;
		while (tokens[index])
		{
			printf("Token [%d]: %s\n", index, tokens[index]);
			index++;
		}
		index = 0;
	}

	return (0);
}			
