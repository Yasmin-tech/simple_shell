#include "main.h"


/**
 * check_usage - checks if the number of command line arguments is
 *	valid to launch the shell program
 * @argc: the number of command line arguments
 *
 * Return: void
 */

void check_usage(int argc)
{
	if (argc > 1)
	{
		write(STDERR_FILENO, "Usage: simple_shell\n", 21);
		exit(2);
	}
}

/**
 * cmd_not_found - handles the case when a command is not found
 * @argv: an array of character pointers representing
 *	the command line arguments
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 * @exit_status: a pointer to an integer representing
 *	the exit status of the command
 *
 * Return: void
 */

void cmd_not_found(char **argv, char **new_argv, int *exit_status)
{
	errmsg(argv, new_argv);
	*exit_status = 127;
	_free(new_argv);
}

/**
 * _free - frees a dynamically allocated array of character pointers
 * @new_argv: the array to be freed
 *
 * Return: void
 */

void _free(char **new_argv)
{

	free(new_argv);
	new_argv = NULL;
}

/**
 * _prompt - prints a prompt to the standard output
 * @prompt: the prompt to be printed
 *
 * Return: void
 */

void _prompt(char *prompt)
{

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, prompt, 2);
}

/**
 * _prompt2 - prints a newline character to the standard output
 *	if the input is from a terminal before exiting the shell
 *
 * Return: void
 */

void _prompt2(void)
{

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
}

