#include "shell.h"
#include <string.h>

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
		tokens[j] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(tokens[j], token);
		j++;
		token = strtok(NULL, " ");
	}
	tokens[j] = NULL;

	return (tokens);
}

/**
 * _exec - executes a given command
 * @argv -  pointer to array containing command and arguments
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
