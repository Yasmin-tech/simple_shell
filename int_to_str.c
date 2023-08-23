#include "main.h"

/**
 * int_to_str - converts an integer to a string
 * @n: the integer to be converted
 * @s: a pointer to a buffer where the resulting string will be stored
 *
 * Return: void
 */

void int_to_str(int n, char *s)
{
	unsigned int divisor = 1, digit, num = n;
	int i;


	while (num / divisor >= 10)
		divisor *= 10;

	i = 0;
	while (divisor != 0)
	{
		digit = num / divisor;
		s[i] = digit + '0';
		num = num % divisor;
		divisor /= 10;
		i++;
	}
	s[i] = '\0';

}
