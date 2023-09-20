#include "header.h"

/**
 * int_to_string - converts integer to string
 * @result: array to hold string
 * @value: integer value to be converted
 *
 * Return: converted string
 */

void int_to_string(int value, char *result)
{
	int temp, position, d, num = 0;

	if (value == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return;
	}
	temp = value;

	while (temp != 0)
	{
		temp /= 10;
		num++;
	}
	position = num;
	result[position] = '\0';

	while (value != 0)
	{
		position--;
		d = value % 10;
		result[position] = '0' + d;
		value /= 10;
	}
}

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: The value
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strcat - concantnates two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Result of two strings together
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0, j;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != 0; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncmp - compares amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @s: amount of characters to compare
 * Return: 0 (successful) otherwise 1
 */
int _strncmp(const char *s1, const char *s2, size_t s)
{
	size_t j;

	if (s1 == NULL)
		return (-1);

	for (j = 0; j < s && s2[j]; j++)
	{
		if (s1[j] != s2[j])
		{
			return (1);
		}
	}
	return (0);
}
