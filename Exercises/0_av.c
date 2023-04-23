#include <stdio.h>

/**
 * main - prints all the command line argument withouth using ac
 * @ac: command line  argument count
 * @av: commmand line argument vector
 *
 * Return: 0 on success
 */
int main(__attribute__((unused))int ac, char **av)
{
	int index = 0;

	while (av[index])
	{
		printf("av[%d]: %s\n", index, av[index]);
		++index;
	}

	return (0);
}
