#include "header.h"

/**
 * execute_and_wait - executes a command and waits for its completion
 * @command_path: path command to execute
 * @tokens: array of commandline arguments
 * @e_status: pointer to store exit status of the command
 *
 * Return: 0 when succeful else 1
 */

int execute_and_wait(char *command_path, char **tokens, int *e_status)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		execve(command_path, tokens, environ);
		perror("Execve");
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*e_status = WEXITSTATUS(status);
		else
			*e_status = -1;
	}
	return (0);
}
