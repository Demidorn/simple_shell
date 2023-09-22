#include "header.h"

/**
 * main - Entry point of the program that displays a prompt
 * whenever the function is called upon.
 * @argc: Number of commandline arguments.
 * @argv: Pointer array of strings containing commandline arguments.
 * @env: An array of strings containing environment variables.
 *
 * Return: 0 when successfull.
 */

int main(int argc, char __attribute__((__unused__)) *argv[])
{
	char *get_address = NULL;
	size_t length_input = 0;
	ssize_t read_line;
	int string_line;

	(void)argc;

	while (1)
	{
		read_line = read_input(&get_address, &length_input);
		if (read_line == -1)
		{
			free(get_address);
			exit(127);
		}
		if (get_address[0] != '\0')
		{
			string_line = execute_command(get_address);
			if (string_line != 0)
				return (string_line);
		}
	}
	free(get_address);
	return (0);
}
