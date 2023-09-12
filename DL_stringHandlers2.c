#include "header.h"

/**
 * _strlen - returns the length of a string
 * @s: The string to get parameter of
 * Return: The length of the @s
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s++)
	length++;
	return (length);

}

/**
 * _strcpy - copies the string pointed to
 * @src: Source value
 * @dest: Destination of value
 * Return: The pointer to dest
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
 * @s: The pointer to convert
 * Return: An integer value(s)
 */

int _atoi(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
	if (s[c] == 45)
	{
	min *= -1;
	}
	while (s[c] >= 48 && s[c] <= 57)
	{
	isi = 1;
	ni = (ni * 10) + (s[c] - '0');
	c++;
	}
	if (isi == 1)
	{
	break;
	}
	c++;
	}
	ni *= min;
	return (ni);
}

/**
 * _strndup - duplicates a string
 * @s: string chars
 *
 * Return: duplicated string otherwise null
 */

char *_strndup(char *s)
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
