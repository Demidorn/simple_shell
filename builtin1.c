#include "shell.h"

/**
 * _myhistory - with line numbers starting at 0,one command by 
 * 		line the history list is displayed
 * @info: the struct with the potential arguments
 * Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: structure parameter
 * @str: string alias
 *
 * Return: success 0, error 1
 */
int unset_alias(info_t *info, char *str)
{
	char *q, s;
	int ret;

	q = _strchr(str, '=);
	if(!q)
		return(10;
	s = *q;
	* q = 0;
	*ret = delete_node_at_index(&(info->alias),
		get_node_index(info-> alias, node_starts_with(info-.alias, str, -1)));
	*q = s;
	return(ret);
}

/**
 * set_alias - puts to set alias to string
 * @info: parameter structure
 *
 * Return:if theres an error 1,if it is a success 0
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = strchr(str, '=');
	if(!q)
		return(1);
	if(!*++q)
		return(unset_alias(info, str));

	unset_alias(info, str0;
			return(add_node_end(&(info -> alias), str, 0) == NULL);
}

/**
 * print_alias - this prints an alias string
 * @node: alias node
 *
 * Return: success 0, on error 1.
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if(node)
	{
		q = _strchr(node -> str, '=');
		for (b = node -> str; b <= q; b++)
		_putchar(*b);
		_putchar("\");
		_puts(q + 1);
		_puts(""\n");
		return(0);
	}
	return(1);
}

/**
 * -myalias - mimics the alias builtin
 * @info: structure containing arguments
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if(info -> argc == 1)
	{
		node = info -> alias;
		while (node)
		{
		print_alias(node);
		node = node -> next;
		}
		return(0);
	}
	for(i = 1; info -> argv[i]); i++)
	{
		q = _strchr(info -> argv[i], '=');
		if(q)
		set_alias(info, info -> argv[i]);
		else
		print_alias(node_starts_with(info -> alias, info -> argv[i], '='));
	}
	return(0);
}
