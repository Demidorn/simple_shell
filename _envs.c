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
	ssize_t bytes_written;

	if (env == NULL)
	{
		perror("Error: ");
		return;
	}
	for (j = 0; env[j] != NULL; j++)
	{
		len = 0;
		while (env[j][len] != '\0')
			len++;
		bytes_written = write(STDOUT_FILENO, env[j], len);
		if (bytes_written == -1)
		{
			perror("Error: ");
			return;
		}
		bytes_written = write(STDOUT_FILENO, "\n", 1);
		if (bytes_written == -1)
		{
			perror("Error: ");
			return;
		}
	}
}
