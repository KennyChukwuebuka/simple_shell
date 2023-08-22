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
 * _prompt - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: prompt
 */

int _prompt()
{
	FILE *filestream = stdin;
	char *line = NULL;
	size_t len = 0;
	ssize_t n_chars;
	char *prmpt = "$ ";

	_printstr(prmpt);
	fflush(stdout);
	n_chars = getline(&line, &len, filestream);

	if (n_chars == -1)
	{
		if (feof(filestream))
		{
			exit(0);
		}
		else
		{
			perror("getline");
			exit(0);
		}
	}
	printf("%s", line);

	free(line);
	line = NULL;
	len = 0;

	free(line);
	/*fclose(filestream);*/

	return (0);
}
