#include "header.h"

/**
 * _printenv - prints path to the environment variable
 *
 * Return: nothing
 */

void _printenv(void)
{
	char **env = environ;
	int j;
	size_t len;

	if (env == NULL)
	{
		perror("Error: environ is not available");
		return;
	}

	for (j = 0; env[j] != NULL; j++)
	{
		len = 0;
		while (env[j][len] != '\0')
			len++;
		write(STDOUT_FILENO, env[j], len);
		write(STDOUT_FILENO, "\n", 1);
	}

}
