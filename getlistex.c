#include "main.h"
/**
 * _putchar - Function that print char
 * @c: Params
 *
 * Return: 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstr - Function that print a string
 * @s: Params
 *
 * Return: String
 */

int _printstr(char *s)
{
	int i = 0, char_count = 0;

	while (s[i])
	{
		char_count += _putchar(s[i++]);
	}
	return (char_count);
}
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always  0
 */

int main(int ac, char **av)
{
	(void)ac;
	FILE *filestream = stdin;
	char *line = NULL;
	size_t len = 0;
	ssize_t n_chars;
	char *prmpt = "$ ";

	while (1)
	{
		_printstr(prmpt);
		n_chars = getline(&line, &len, filestream);

		if (n_chars == -1)
		{
		free(line);
		exit(0);
		}
		free(line);
		line = NULL;
		len = 0;
	}
	return (0);
}
