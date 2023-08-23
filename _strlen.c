#include "main.h"

/**
 * _strlen - a function that swaps the values of two integers
 * @s: string pointer
 *
 * Return: void
 */

int _strlen(char *s)
{
	int len = 0;
	/*char *copy = s;*/

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
