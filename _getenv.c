#include "header.h"

/**
 * _getenv - gets an env variable from the path
 * @str: name of the variable to get
 *
 * Return: value of the env variable else null
 */

char *_getenv(const char *str)
{
	size_t len;
	char *value;
	int l;

	len = _strlen(str);

	if (str == NULL || environ == NULL)
	{
		perror("Error: ");
		return (NULL);
	}

	for (l = 0; environ[l]; l++)
	{
		if (_strncmp(str, environ[l], len) == 0 && environ[l][len] == '=')
		{
			value = _strdup(environ[l] + len + 1);
			if (value == NULL)
			{
				/*free(value);*/
				perror("Error: ");
				return (NULL);
			}
			return (value);
		}
	}
	return (NULL);
}

/**
 * read_input - function that reads a line of input
 * @get_address: poniter to store input
 * @length_input: stores length of the input line
 *
 * Return: number of characters read otherwise -1 on failure
 */

ssize_t read_input(char **get_address, size_t *length_input)
{
	char *prompt = "$ ";
	ssize_t read_line;
	int is_terminal = isatty(0);

	if (is_terminal == 1)
		write(STDOUT_FILENO, prompt, 2);
	read_line = getline(get_address, length_input, stdin);
	return (read_line);
}
