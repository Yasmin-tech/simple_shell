#include "main.h"

void execute(char *buf, char *av);

/**
 1 - while (true) 
 	1 - Display a prompt and wait for the user to type a command ($) ....
	2 - read the line
	3 - if (end of file )
		- exit
	4 - the command is a full path /bin/ls
	5 - execute the command
	6 - f an executable cannot be found, print an error message and display the prompt again
 */
int main(int ac, char *argv[])
{
    /* promp to allow entering a commamnd*/
	char *prompt = "($) ";
	char *buf = NULL;
	size_t size_buf = 0;
	ssize_t line_r = 0;
	pid_t pid;

	if(ac != 1)
	{
		perror("failed");
		return(1);
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, 4);
	    /* read the line and store in lineptr*/
		line_r = getline(&buf, &size_buf, stdin);
		if (line_r == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(buf);
			break;
		}
		if (line_r >  1)
		{
			buf[line_r - 1] = '\0';
			pid = fork();

			if (pid == 0)
			{
				execute(buf, argv[0]);
			}
			else
			{
				wait(NULL);
			}
		}
		free(buf);
		buf = NULL;
	}

	return (0);

}
    
void execute(char *buf, char *av)
{
	int val = 0;
	char *argv[2];

	argv[0] = buf;
	argv[1] = NULL;

	val = execve(buf, argv , NULL);

	if (val == -1)
	{
		perror(av);
		free(buf);
		exit(1);

	}
}




















