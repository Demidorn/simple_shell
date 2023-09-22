#include "header.h"

/**
 * locate_path - checks for path of the variable executed
 * @com_val: Pointer to string values
 * Return: 0 when successful otherwise -1
 */
char *locate_path(char *com_val)
{
	char *read_path = NULL, *file = NULL, *token_to_path;
	size_t length, dir_length;
	struct stat buff;

	if (stat(com_val, &buff) == 0)
	{
		file = _strdup(com_val);
		return (file);
	}
	read_path = _getenv("PATH");
	if (!read_path)
		return (NULL);
	token_to_path = strtok(read_path, ":");

	while (token_to_path != NULL)
	{
		dir_length = _strlen(token_to_path);
		length = _strlen(com_val);
		file = malloc(dir_length + length + 2);
		if (!file)
		{
			free(read_path);
			return (NULL);
		}
		_strcpy(file, token_to_path);
		_strcat(file, "/");
		_strcat(file, com_val);
		if (stat(file, &buff) == 0)
		{
			free(read_path);
			return (file);
		}
		free(file);
		token_to_path = strtok(NULL, ":");
	}
	free(read_path);
	return (NULL);
}
