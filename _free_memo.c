#include "header.h"

/**
 * _free_memo - 
 *
 */
void _free_memo(char *args[])
{
	int i;

	if (args == NULL ||args[0] == NULL)
		return;
	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	if (args)
		free(args);
}
