#include "main.h"

/**
 * contains - checks if a string contains a specified substring
 * @str1: the string to be searched
 * @str2: the substring to search for
 *
 * Return: 1 if the substring is found in the string, 0 otherwise
 */

int contains(char *str1, char *str2)
{
	char *ptr;

	ptr = _strstr(str1, str2);

	if (ptr == NULL)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

