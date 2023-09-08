#include "headr.h"

/**
 * main - Entry point of the program that displays a prompt
 * whenever the function is called upon.
 * @argc: Number of commandline arguments.
 * @argv: Pointer array of strings containing commandline arguments.
 * @env: An array of strings containing environment variables.
 *
 * Return: 0 when successfull.
 */

int main(int argc, char *argv[], char **env)
{
	char *prompt = "$ ", *get_address = NULL, *delim = " \n\t\r";
	char **tokens = NULL, *command_path = NULL;
	ssize_t read_line;
	size_t length_input = 0;
	pid_t pid;
	int status, is_terminal = isatty(0), len, ex = 0;

	(void)argc;

	while (1)
	{
		if (is_terminal == 1)
			write(STDOUT_FILENO, prompt, 2);
		read_line = getline(&get_address, &length_input, stdin);
		if (read_line == -1)
		{
			free(get_address);
			exit(127);
		}
		if (get_address[0] != '\0')
		{
			tokens = tokenize(get_address, delim);
			if (!tokens || tokens[0] == NULL)
			{
				/*perror("Tokenization failed");*/
				continue;
			}
			if (strcmp(command_path, "exit") == 0)
			{
				free(tokens);
				free(command_path);
				exit(ex);
			}
			if (strcmp(command_path, "env") == 0)
			{
				_printenv();
				free(tokens);
				free(command_path);
				continue;
			}
			command_path = locate_path(tokens[0]);
			if (!command_path)
			{
				perror("command not found");
				free(tokens);
				ex = 127;
				continue;
			}
			pid = fork();
			if (pid == 0)
			{
				execve(command_path, tokens, env);
				perror(argv[0]);
				exit(2);
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
				{
					ex = WEXITSTATUS(status);
				}
				free(command_path);
				free(tokens);
			}
		}
	}
	return (ex);
}
