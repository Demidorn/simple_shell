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
	char **m_token = malloc((MAX_TOKEN + 1) * sizeof(char *));

	/*if (m_token == NULL)*/
	if (!m_token)
	{
		perror("Error: ");
		return (NULL);
	}
	token = strtok(buffer, delim);

	while (token != NULL && token_count < MAX_TOKEN)
	{
		m_token[token_count] = _strdup(token);
		/*if (m_token[token_count] == NULL)*/
		if (!m_token[token_count])
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
		token = strtok(NULL, delim);
	}
	m_token[token_count] = NULL;
	return (m_token);
}
