#include "shell.h"

/**
 * main - entry point to the shell program
 *
 * Return: always 0
 */

int main(void)
{
	char **tok;
	char *lineptr = NULL;
	size_t n = 0;
	int charead;
	int status, i = 0;
	pid_t ch_pid;

	while (1)
	{
		write(1, "$ ", 2);
		fflush(stdout);

		if ((charead = getline(&lineptr, &n, stdin)) == -1)
		{
			perror("error in getline");
			exit(EXIT_FAILURE);
		}
	
		while (lineptr[i] != '\0')
		{
			if (lineptr[i] == '\n')
				lineptr[i] = '\0';
			i++;
		}

		tok = _strtok(lineptr);

		if (tok != NULL)
		{
			ch_pid = fork();
			if (ch_pid == -1)
			{
				perror("error in fork");
				exit(EXIT_FAILURE);
			}

			if (ch_pid == 0)
			{
				_exec(tok);
			}

			else
			{
				wait(&status);
			}
		}

		i = 0;
		_free(tok);

	}


	return (0);
}
