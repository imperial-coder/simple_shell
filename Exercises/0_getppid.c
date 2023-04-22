#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - prints the parent process id
 *
 * Return: 0 on sucess
 */
int main(void)
{
	pid_t ppid;

	/* getting the ppid */
	ppid = getppid();

	/* printing the ppid */
	printf("The parent process ID is: %u\n", ppid);

	return (0);
}
