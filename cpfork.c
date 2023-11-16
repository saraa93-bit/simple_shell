#include "main.h"
/**
 * _free - frees the memory
 * @ptr: pointer to the memory
 * Return: 1 if successful, 0 if not
 */
int _free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
