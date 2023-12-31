#include "main.h"

/**
 *_realloc -  a function that reallocates a memory block using malloc and free
 *@ptr: a pointer to a prevoiusly allocated memory with malloc
 *@old_size: the initiale size of the allocated memory
 *@new_size: the new size of what ptr is pointing to
 *
 * Return: a integer pointer to the new block of memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	unsigned char *p = ptr, *pp = ptr;
	unsigned int i, flag, len;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	else if (ptr && !new_size)
	{
		free(ptr);
		return (NULL);
	}
	else if (old_size == new_size)
	{
		return (ptr);
	}
	else
	{
		pp = malloc(new_size);
		/*ptr = pp;*/

		if (p != pp)
			flag = 1;

		len = old_size < new_size ?
			old_size : new_size;
		for (i = 0; i < len; i++)
			*pp++ = (unsigned char) *p++;

		if (flag)
			free(ptr);
	}
	return ((void *) (pp - len));
}
