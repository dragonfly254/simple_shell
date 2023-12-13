#include <stdio.h>

/**
 * main - prints the environment
 * @ac: arguments count
 * @av: array of the arguments
 * @env: environment variable
 *
 * Return: Always 0.
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
