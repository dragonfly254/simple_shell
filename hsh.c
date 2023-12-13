#include "shell.h"

/**
 * main - entry point to the shell program
 *
 * Return: always 0
 */
int main(void)
{
	char **tok;
	char *lineptr;
	int status, __attribute__((unused)) i = 0;
	pid_t ch_pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		fflush(stdout);
		lineptr = _getline();

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
