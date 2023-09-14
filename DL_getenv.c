#include "header.h"

/**
 * _getenv - gets an env variable from the path
 * @str: name of the variable to get
 *
 * Return: pointer to the env variable else null
 */

char **_getenv(const char *str)
{
	int lens, j;

	lens = _strlen((char *)str);

	for (j = 0; environ[j]; j++)
	{
		if (_strncmp(str, environ[j], lens) == 0)
			return (&environ[j]);
	}
	return (NULL);
}
