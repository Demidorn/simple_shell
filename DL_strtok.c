#include "header.h"

/**
 * _strtok - extracts tokens of a string
 * @fem: the delimiter
 * @str: string array of pointer to tokens
* Return: pointer to next token or null
 */

char *_strtok(char *str, const char *fem)
{
        static char *temp;
        static char *s_tok;
        long int d;

        if (str == NULL && fem == NULL)
                return (NULL);
        if (str != NULL)
                s_tok = str;
        temp = s_tok;
        if (temp == NULL)
                return (NULL);
        for (d = 0; s_tok[d] != 0; d++)
        {
                if (find_delim(s_tok[d], fem) == 1)
                        break;
        }
        if (s_tok[d] == 0 || s_tok[d] == 35)
        {
                return (NULL);
        }
        temp = s_tok + d;
        s_tok = temp;
        for (d = 0; s_tok[d] != 0; d++)
	{
                if (find_delim(s_tok[d], fem) == 0)
                        break;
        }
        if (s_tok[d] == 0)
                s_tok = NULL;
        else
        {
                s_tok[d] = 0;
                s_tok += d + 1;
        }
        return (temp);
}
