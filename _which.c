#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * main - checks if given file exists
 * @argc: the arguments count
 * @argv: array of arguments
 *
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	int j = 1;

	for (; j < argc; j++)
	{
		if (access(argv[j], F_OK) == 0)
		{
			printf("%s exists\n", argv[j]);
		}
		else
		{
			printf("%s does not exists\n", argv[j]);
		}
	}
	return (0);
}
