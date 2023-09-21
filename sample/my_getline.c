#include "header.h"

/**
 * _getline - reads line from standard imput
 *
 * Return: ouput from stdin
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer = *n;
	ssize_t str = 0;
	int  c, i = 0;
	char *new_address;

	if (*lineptr == NULL || *n == 0)
	{
		buffer = BUFFER_SIZE;
		*lineptr = (char *)malloc(buffer);
		if (*lineptr == NULL)
		{
			perror("Memory allocation failed");
			return (-1);
		}

	}

	while (1)
	{
		c = fgetc(stream);
		if (c == '\n')
		{
			(*lineptr)[str] = '\0';
			return (str);
		}
		if (c == '#')
		{
			i = 1;
			continue;
		}
		if (i == 0 && (c == ' ' || c == '\t'))
			continue;
		if (c != EOF)
		{
			if (str >= (ssize_t)(buffer - 1))
			{
				buffer *= 2;
				new_address = (char *)realloc(*lineptr, buffer);
				if (new_address == NULL)
				{
					perror("Memory allocation failed");
					return (-1);
				}
				*lineptr = new_address;
			}
			(*lineptr)[str] = (char)c;
			str++;
			if (c == EOF)
				break;
		}
	}
	if (str == 0 && c == EOF)
	{
		return (-1);
	}
	(*lineptr)[str] = '\0';
	*n = buffer;
	return (str);
}
