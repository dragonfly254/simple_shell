#include "shell.h"

/**
 * _strtok - splits a given string into tokens
 * @str: string to be tokenised.
 *
 * Return: array of tokens.
 */
char **_strtok(char *str)
{
	char **tokens;
	char *token;
	int words = 0;
	int j = 0, i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			words++;
	}

	tokens = malloc(sizeof(char *) * (words + 1));

	token = strtok(str, " ");
	while (token != NULL)
	{
		tokens[j] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(tokens[j], token);
		j++;
		token = strtok(NULL, " ");
	}
	tokens[j] = NULL;

	return (tokens);
}

/**
 * _exec - executes a given command
 * @argv: pointer to array containing command and arguments
 */
void _exec(char **argv)
{
	if ((execve(argv[0], argv, NULL)) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}


/**
 * _free - frees an array of strings.
 * @ptr: pointer to the array to be freed.
 *
 */
void _free(char **ptr)
{
	int j = 0;

	if (ptr == NULL)
		exit(EXIT_SUCCESS);

	for (; ptr[j] != NULL; j++)
	{
		free(ptr[j]);
	}
	free(ptr);
}

/**
 * _getline - gets the line from prompt.
 *
 * Return: pointer to line read from prompt.
 */
char *_getline(void)
{
	ssize_t charead;
	char *lineptr = NULL;
	size_t n = 0;
	int i = 0;

	charead = getline(&lineptr, &n, stdin);
	if (charead == -1)
	{
		exit(EXIT_FAILURE);
	}

	while (lineptr[i] != '\0')
	{
		if (lineptr[i] == '\n')
			lineptr[i] = '\0';
		i++;
	}

	return (lineptr);
}
