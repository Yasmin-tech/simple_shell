#include "main.h"

int is_valid_path(char *command, struct stat st);
int is_path(char *command);

/**
 * _getenv - searches for the value of an environment variable
 * @str1: the name of the environment variable to search for
 *
 * Return: a pointer to the value of the environment variable, or NULL if
 *         the environment variable is not found or if the input is invalid
 */

char *_getenv(char *str1)
{
	char *env = str1;
	/*char **available_envs = str2;*/
	char *curr_env;
	int i, j, flag = 0;

	if (env == NULL || (_strlen(env) == 0))
		return (NULL);
	i = 0;
	while (environ[i])
	{
		j = 0;
		flag = 0;
		curr_env = environ[i];

		while (env[j] && (curr_env[j] != '='))
		{
			if (env[j] != curr_env[j])
			{
				flag = 1;
				break;
			}
			j++;
		}
		if (!flag)
			break;
		i++;
	}
	if (!flag)
	{
		return (curr_env + j + 1);
	}
	else
	{
		return (NULL);
	}

}

/**
 * handle_path - searches for the full path of a command
 * @command: the command to search for
 * @find: a pointer to a buffer where the full path
 *	of the command will be stored
 *
 * Return: a pointer to the full path of the command,
 *	or NULL if the command is not found
 */

char *handle_path(char *command, char **find)
{
	char *PATH = _getenv("PATH");
	char *ptr = PATH;
	int i, j;
	struct stat st;
	int found = 0;

	if (is_path(command))
	{
		if (!is_valid_path(command, st))
		{
			*find = strcpy(*find, command);
			return (*find);
		}
		else
		{
			*find = NULL;
			return (*find);
		}
	}
	if (ptr == NULL)
	{
		*find = NULL;
		return (*find);
	}
	i = 0;
	while (ptr[i])
	{
		_memset(*find, '\0', 1024);
		j = 0;
		while (ptr[i] != ':' && ptr[i] != '\0')
		{
			(*find)[j] = ptr[i];
			i++;
			j++;
		}
		if ((*find)[j - 1] != '/')
		{
			(*find)[j] = '/';
		}

		_strcat(*find, command);
		found = stat(*find, &st);

		if (!found)
		{
			return (*find);
		}
		if (ptr[i] == ':')
			i++;
		else
			break;
	}
	*find = NULL;
	return (*find);
}

/**
 * is_path - checks if a given command is  a path
 * @command: the command to check
 *
 * Return: 1 if the command contains a path, 0 otherwise
 */

int is_path(char *command)
{
	int i, path = 0;

	i = 0;
	while (command[i])
	{
		if (command[i] == '/')
		{
			path = 1;
			break;
		}
		i++;
	}
	/*printf("is_path = %d\n", path);*/
	return (path);

}

/**
 * is_valid_path - checks if a given command is a valid path
 * @command: the command to check
 * @st: a stat structure to store information about the file
 *
 * Return: 0 if the command is a valid path, -1 otherwise
 */

int is_valid_path(char *command, struct stat st)
{
	int valid;

	valid = stat(command, &st);

	return (valid);
}
