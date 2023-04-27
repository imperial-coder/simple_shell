#include "shell.h"

/**
 * signal_handler - checks the signal
 * @n: signal value
 *
 * Return: void
 */
void signal_handler(int n)
{
	(void)n;

	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
