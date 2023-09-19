#include "shell.h"

/**
 * is_chain - check if current character in buffer is a 
 * 		chain delimeter
 * @info: structer parameter
 * @buf: buffer character
 * @p; address of current position in buffer
 *
 * Return: if successful 1, if it fail 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t
