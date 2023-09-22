#include "header.h"

/**
 * execute_command - function to handle command execution based on user input
 * @get_address: input line from user
 *
 * Return: output executed command else -1
 */
int execute_command(char *get_address)
{
	char *delim = " \n\t\r";
	char **tokens = NULL, *command_path = NULL;
	int status = 0, ex = 0;

	tokens = tokenize(get_address, delim);
	if (!tokens || tokens[0] == NULL)
	{
		perror("Error ");
		_free_memo(tokens);
		return (-1);
	}
	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
			status = _atoi(tokens[1]);
		_free_memo(tokens);
		free(get_address);
		exit(status);
	}
	if (_strcmp(tokens[0], "env") == 0)
	{
		_printenv();
		_free_memo(tokens);
		free(command_path);
		return (ex);
	}
	command_path = locate_path(tokens[0]);
	if (!command_path)
	{
		perror("command not found");
		_free_memo(tokens);
		ex = 127;
		return (ex);
	}
	execute_and_wait(command_path, tokens, &ex);
	_free_memo(tokens);
	free(command_path);
	return (ex);
}
