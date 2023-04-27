#include "shell.h"

/**
 * find_path - finds path
 *
 * Return: NULL or path.
 */
char *find_path(void)
{
	int y;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && y < 5)
			{
				path++;
				y++;
			}
			return (path);
		}
	env++;
	}

	return (NULL);
}
