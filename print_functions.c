#include "shell.h"

/**
 * _putchar - writes to stdout
 * @c: char
 *
 * Return: 1 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string
 * @s: string to be printed
 *
 * Return: number of characters printed
 */
int print_str(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
