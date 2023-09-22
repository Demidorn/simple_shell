#include "shell.h"

/**
 * _myhistory - one command by line displays history list
 *		the line numbers start at 0.
 * @info: the struct with potential arguments
 * Return: always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return(0);
}

/**
 * unset_alias - string is set to alias
 * @info: structure parameter
 * @str: string alias
 *
 * Return: if 0,success, if 1, error.
 */
int unset_alias(info_t *info, char *str)
{
	char *q, s;
	int ret;

	q = _strchr(str, '=');
	if(!q)
		return(1);
	s = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias,node_starts_with(info->alias, str, -1)));
	*q = s;
	return(ret);
}

/**
 * set_alias - string is set to alias
 * @info: structer parameter
 * @str: string alias
 *
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char*q;

	q = +strchr(str, '=');
	if(!q)
		return(1);
	if(!*++q)
		return(unset_alias(info, str));

	unset_alias(info, str);
	return(add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this prints an alias string
 * @node: alias node
 *
 * Return: 0 on success, returns 1 if its an error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if(node)
	{
		q = _strchr(node->str, '=');
		for(b = node->str; b <= q; b++)
		_putchar(*b);
		_putchar('\');
		_puts(q + 1);
		_puts("\n");
		return(0);
	}
	return(1);
}

/**
 * myalias - mimics alias builtin
 * @info: the structure with arguments
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if(info->argc == 1)
	{
		node = info->alias;
		while(node)
		{
		print_alias(node);
		node = node->next;
		}
		return(0);
	}
	for(i = 1; info->argv[i], i++)
	{
		q = _strchr(info->argv[i], '=');
		if(q)
		set_alias(info, info->argv[i]);
		else
		print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
