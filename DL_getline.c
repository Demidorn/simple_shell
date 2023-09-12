#include "header.h"

/**
 * _getline - reads line from standard imput
 *
 * Return: ouput from stdin
 */

char *_getline()
{
	int buffer = BUFFER_SIZE;
	char *str = malloc(buffer);
	int i = 0, c;

	if (!str)
	{
		perror("Error ");
		return (NULL);
	}

	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			str[i] = '\0';
			break;
		}
		else
		{
			str[i] = c;
			i++;
			if ((i >= buffer) == 1)
			{
				buffer += BUFFER_SIZE;
				str = realloc(str, buffer);
				if (!str)
				{
					perror("Error");
					return (NULL);
				}
			}
		}
	}
	return (str);
}
