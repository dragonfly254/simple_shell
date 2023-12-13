#include <stdio.h>

/**
 * main - prints the environment
 * @ac: arguments count
 * @av: array of the arguments
 * @env: environment variable
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
