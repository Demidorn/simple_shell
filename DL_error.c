#include "header.h"

/**
 * _error - writes error message to sdterr
 * @args: array of arguments
 * @error_msg: error
 *
 * Return: Error
 */

void _error(const char *args, int error_msg)
{
	char *buffer = (char *)malloc(sizeof(char));
	char str_error[100];

	if (access(args, F_OK) != 0)
	{
		strcpy(buffer, "File not found\n");
	}
	else
	{
		strcpy(buffer, "Error: ");
		strcat(buffer, args);
		strcat(buffer, ", Error_msg: ");
		int_to_string(error_msg, str_error);
		strcat(buffer, str_error);
		strcat(buffer, "\n");
	}
	write(STDERR_FILENO, buffer, strlen(buffer));
	free(buffer);
}
