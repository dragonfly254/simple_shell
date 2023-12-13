#include "shell.h"

/**
 * _strlen - computes the length of the string.
 *
 * @s: input string.
 *
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*(s + counter) != '\0')
	{
		counter++;
	}
	return (counter);
}

/**
 * _strcpy - copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 *
 * @dest: destination.
 * @src: source
 *
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
