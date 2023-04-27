#include "shell.h"

/**
 * _strlen - gets the lenght
 * @s: str
 *
 * Return: length
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count])
		count++;

	return (count);
}

/**
 * _strdup - dups a string
 * @s: str to dup
 *
 * Return: dupped string
 */
char *_strdup(char *s)
{
	char *ptr;
	int i, j;

	if (s == NULL)
		return (NULL);

	j = _strlen(s);

	ptr = malloc(sizeof(char) * (j + 1));
	if (!ptr)
		return (NULL);

	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference
 */
int _strcmp(char *s1, char *s2)
{
	int j = 0, diff;

	while (*(s1 + j) == *(s2 + j) && *(s1 + j) != '\0')
		j++;

	diff = (*(s1 + j) - *(s2 + j));

	return (diff);
}

/**
 * _strchr - find a character in a string
 * @s: sttring to be searched
 * @c: character to search for
 *
 * Return: address of found character
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
