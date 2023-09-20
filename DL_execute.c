#include "header.h"

/**
 * execute_command - function to handle command execution based on user input
 * @get_address: input line from user
 * @env: environment variable
 *
 * Return: output executed command else -1
 */

int execute_command(char *get_address, char __attribute__((__unused__)) **env)
{
	char *delim = " \n\t\r";
	char **tokens = NULL, *command_path = NULL;
	int status = 0, ex = 0;

	tokens = tokenize(get_address, delim);
	if (!tokens || tokens[0] == NULL)
	{
		perror("Error ");
		return (ex);
	}
	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			status = atoi(tokens[1]);
		}
		free(tokens);
		free(command_path);
		exit(status);
	}
	if (_strcmp(tokens[0], "env") == 0)
	{
		_printenv();
		free(tokens);
		free(command_path);
		return (ex);
	}
	command_path = locate_path(tokens[0]);
	if (!command_path)
	{
		perror("command not found");
		free(tokens);
		ex = 127;
		return (ex);
	}
	execute_and_wait(command_path, tokens, &ex);
	return (ex);
}
