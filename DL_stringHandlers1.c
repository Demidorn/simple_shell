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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: Int  value
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0, b = 0, c = 0, r = 0, lim;

	while (s1[a])
	{
		a++;
	}

	while (s2[b])
	{
		b++;
	}

	if (a <= b)
	{
		lim = a;
	}
	else
	{
		lim = b;
	}

	while (c <= lim)
	{
		if (s1[c] == s2[c])
		{
			c++;
			continue;
		}
		else
		{
			r = s1[c] - s2[c];
			break;
		}

		c++;
	}

	return (r);
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
 * _puts - declares a string to standard output
 * @str: To be checked
 * Return: Nothing
 */

void _puts(char *str)
{
	for (; *str != '\0'; str++)
	{
	_putchar(*str);
	}
	_putchar('\n');
}
