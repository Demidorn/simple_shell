#include "header.h"

/**
 * prog_setenv - Modifies an environment variable to the path
 * @args: An array of arguments
 * @ard: Double pointer to arguments
 *
 * Return: 1 if error occurs otherwise 0
 */

int prog_setenv(char **args, char __attribute__((__unused__)) **ard)
{
	char **old_value = NULL, *new_value, **new_env;
	size_t size = 0;
	int start;

	if (!args[0] || !args[1])
		_error(args[0], -1);
	new_value = malloc((_strlen(args[0]) + 1) + (_strlen(args[1]) + 1));
	if (!new_value)
		_error(args[0], -1);
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);
	old_value = _getenv(args[0]);
	if (old_value)
	{
		free(*old_value);
		*old_value = new_value;
		return (0);
	}

	while (environ[size])
		size++;
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_value);
		_error(args[0], -1);
	}
	for (start = 0; environ[start]; start++)
		new_env[start] = environ[start];
	free(environ);
	environ = new_env;
	environ[start] = new_value;
	environ[start + 1] = NULL;
	return (0);
}

/**
 * prog_unsetenv - Deletes an environment variable from the path
 * @args: Array of arguments
 * @ard: Double pointer arguments
 *
 * Return: -1 if error occurs otherwise 0
 */

int prog_unsetenv(char **args, char __attribute__((__unused__)) **ard)
{
	char **env_var, **new_env;
	size_t start = 0;
	int i, j;

	i = j = 0;
	if (!args[0])
		_error(args[0], -1);
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	while (environ[start])
		start++;
	new_env = malloc(sizeof(char *) * start);
	if (!new_env)
		_error(args[0], -1);

	while (environ[i])
	{
		if (*env_var == environ[i])
		{
			free(*env_var);
			continue;
		}
		new_env[j] = environ[i];
		i++;
		j++;
	}
	free(environ);
	environ = new_env;
	environ[start - 1] = NULL;
	return (0);
}

/**
 * _printenv - prints path to the environment variable
 *
 * Return: ....
 */

void _printenv(void)
{
	char **env = environ;
	
	while (*env != NULL)
	{
		print_env_variable(*env);
		env++;
	}
}

/**
 * print_env_variable - displays output of the environment variable
 * @str: string that holds the outputted env variable
 *
 * Return: ...
 */

void print_env_variable(const char *str)
{
	size_t len = _strlen(str);

	write(STDOUT_FILENO, str, len);
	write(STDOUT_FILENO, "\n", 1);
}
