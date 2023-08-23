#include "main.h"

/**
 * handle_builtin - handles built-in commands
 * @command: the command to be executed
 * @argv: array of character pointers representing the command line arguments
 * @buf: the input buffer containing the command to be executed
 * @new_argv: an array of character pointers representing the tokenized command
 * @exit_status: the exit status of the previous command
 *
 * Return: void
 */

void handle_builtin(char *command, char **argv, char *buf,
		char **new_argv, int exit_status)
{
	int status, res_atoi;

	if (command == NULL)
		return;
	if (!(_strcmp(command, "exit")))
	{
		if (new_argv[1])
		{
			res_atoi = _atoi(new_argv[1]);
			if (res_atoi < 0)
			{
				status = 2;
				errmsg2(argv, new_argv);
			}
			else
			{
				status = res_atoi;
			}
		}
		else
		{
			status = exit_status;
		}

		free(buf);
		free(new_argv);
		exit(status);
	}

	if (!(strcmp(command, "env")))
		print_env(new_argv);

	_echo(new_argv, exit_status);

	handle_comments(new_argv);

}

/**
 * print_env - prints the current environment variables
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 *
 * Return: void
 */

void print_env(char **new_argv)
{
	int i;

	i = 0;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	new_argv[0] = NULL;
}

/**
 * _echo - Handle variables replacement
 * @new_argv: an array of character pointers representing the tokenized command
 * @exit_status: the exit status of the previous command
 *
 * Return: void
 */

void _echo(char **new_argv, int exit_status)
{
	pid_t ppid = getpid();
	int i, j = 0;
	char *op = NULL, *var;
	static char arr[500][12];

	i = 0;
	/*memset(arr, 0, sizeof(arr));*/
	if (new_argv[0] == NULL)
		return;
	/*if (new_argv[i] || contains(new_argv[i], "echo"))*/

	while (new_argv[i])
	{
		op = new_argv[i];
		if (op[0] == '\\')
			op = op + 1;
		if (op[0] == '$')
		{
			if (op[1] == '$')
			{
				int_to_str(ppid, arr[++j]);
				op = _strcat(arr[j], op + 2);
				new_argv[i] = op;
			}
			else if (op[1] == '?')
			{
				int_to_str(exit_status, arr[++j]);
				op = _strcat(arr[j], op + 2);
				new_argv[i] = op;
			}
			else
			{
				var = op + 1;
				replace_path(new_argv, var, i);
			}
		}
		i++;
	}

}

/**
 * replace_path - replaces a variable with its value in the
 *	environment if it is found
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 * @var: the name of the variable to be replaced
 * @i: the index of the variable in the new_argv array
 *
 * Return: void
 */

void replace_path(char **new_argv, char *var, int i)
{
	char *env;


	if (var[0] == ' ' || var[0] == '\0')
		return;
	env = _getenv(var);

	if (env == NULL)
		new_argv[i] = "";
	else
		new_argv[i] = env;
}

/**
 * handle_comments - handles comments in a command line begins with (#)
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 *
 * Return: void
 */

void handle_comments(char **new_argv)
{
	int i;
	char *str;

	if (new_argv[0] == NULL)
		return;

	i = 0;
	while (new_argv[i])
	{
		str = new_argv[i];

		if (str[0] == '#')
			new_argv[i] = NULL;

		i++;
	}
}

