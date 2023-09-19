#include "header.h"

/**
 * _execute - code that executes the execve commands
 * @args: pointer to string array
 * @envp: array to pointer of environment variable
 *
 * Return: 0 successful
 */

int _execute(char *args, char **envp)
{
	char **argv;
	/*int kai;*/
	struct stat buff;

	argv = malloc(sizeof(char *));
	if (argv == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	argv[0] = strtok(args, " \t\n");
	if (argv[0] == NULL)
	{
		free(argv);
		return (0);
	}
	/*check if file exists*/
	if (stat(argv[0], &buff) == -1)
	{
		perror("Error: ");
		free(argv);
		exit(EXIT_FAILURE);
	}
	execve(argv[0], argv, envp);
	/*print error if execve failed*/
	perror("Error execve:");
	free(argv);
	exit(EXIT_FAILURE);
}
