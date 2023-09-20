#include "header.h"

/**
 * _strlen - counts the length of a string
 * @s: string to be counted
 * Return: length of the string
 */

int _strlen(const char *s)
{
	int length = 0;

	if (s == NULL)
		return (length);

	for (; s[length] != '\0'; length++)
		continue;
	return (length);
}

/**
 * _strcpy - copies the string pointed to
 * @src: Source value
 * @dest: Destination of value
 * Return: Destination of string
 */

char *_strcpy(char *dest, char *src)
{
	int j;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	dest[j++] = '\0';
	return (dest);
}

/**
 * _atoi - converts string into a integer
 * @s: string to be changed
 * Return: An integer value(s) of converted string(s)
 */

int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (2);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0' && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}

/**
 * _strdup - duplicates a string
 * @s: string chars
 *
 * Return: duplicated string otherwise null
 */

char *_strdup(char *s)
{
	char *j;
	size_t k, m = 0;

	k = _strlen(s);
	j = malloc(sizeof(char) * (k + 1));
	if (!j)
	{
		return (NULL);
	}

	while (m <= k)
	{
		j[m] = s[m];
		m++;
	}
	return (j);
}
