#include <stddef.h>

/**
 * _strstr - find substring
 *@haystack: a string pointer to look for another string
 * occures in sequintial order
 *@needle: the substring to  be looked for
 *
 * Return: char * pointer to haystack where needle first occurese
 */

char *_strstr(char *haystack, char *needle)
{
	char *p1, *p2 = needle;

	for (p1 = haystack; *p1; p1++)
	{

		char *pp1 = p1;

		while (*pp1 == *p2 && *p2)
		{

			pp1++;
			p2++;
		}
		if (!*p2)
			return (p1);

		p2 = needle;
	}


	return (NULL);
}
