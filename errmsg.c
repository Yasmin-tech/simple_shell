#include "main.h"

/**
 * errmsg - prints an error message when a command is not found
 * @argv: an array of character pointers representing
 *	the command line arguments
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 *
 * Return: void
 */

void errmsg(char **argv, char **new_argv)
{

	char *msg[7];
	int i;

	msg[0] = argv[0];
	msg[1] = ": ";
	msg[2] = "1: ";
	msg[3] = new_argv[0];
	msg[4] = ": ";
	msg[5] = "not found";
	msg[6] = "\0";

	for (i = 0; i < 7; i++)
	{
		write(STDERR_FILENO, msg[i], _strlen(msg[i]));
	}

	write(STDERR_FILENO, "\n", 1);
}

/**
 * errmsg2 - prints an error message when an illegal number is
 *	encountered for the exit status
 * @argv: an array of character pointers representing
 *	the command line arguments
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 *
 * Return: void
 */

void errmsg2(char **argv, char **new_argv)
{
	int i;
	char *msg[8];

	msg[0] = argv[0];
	msg[1] = ": ";
	msg[2] = "1: ";
	msg[3] = new_argv[0];
	msg[4] = ": ";
	msg[5] = "Illegal number: ";
	msg[6] = new_argv[1];
	msg[7] = "\0";

	for (i = 0; i < 8; i++)
	{
		write(STDERR_FILENO, msg[i], _strlen(msg[i]));
	}

	write(STDERR_FILENO, "\n", 1);

}
