#include <stdio.h>

/**
 * main - prints "$ ", wait for the user to enter a command
 * prints it on the next line
 *
 * Return: 0 on success
 */
int main(void)
{
	char *lineptr;
	size_t n = 0;
	char *prompt = "$ ";
	ssize_t num_char_read;

	/* creating an infinte loop that only exits when an EOF is encountere */
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
	}

	return (0);
}			
