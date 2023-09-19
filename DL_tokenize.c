#include "header.h"

#define MAX_TOKEN 100

/**
 * tokenize - Tokenizes a string using a given delimiter
 * @buffer: input string to tokenize
 * @delim: delimiter used for tokennization
 *
 * Return: An array of tokens (strigs)
 */

char **tokenize(char *buffer, const char *delim)
{
	int i, token_count = 0;
	char *token;
	char **m_token = malloc(MAX_TOKEN * sizeof(char *));

	if (m_token == NULL)
	{
		perror("Error: ");
		return (NULL);
	}
	token = strtok(buffer, delim);

	while (token != NULL && token_count < MAX_TOKEN)
	{
		m_token[token_count] = strdup(toke);
		if(m_token[token_count] == NULL)
		{
			perror("Memory allocation failed");
			for (i = 0; i < token_count; i++)
			{
				free(m_token[i]);
			}
			free(m_token);
			return (NULL);
		}
		token_count++;
		if (token_count >= MAX_TOKEN)
		{
			break;
		}
		token = strtok(NULL, delim);
	}
	m_token[token_count] = NULL;
	return (m_token);
}
