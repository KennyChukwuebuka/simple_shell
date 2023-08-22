#include "main.h"
/**
 * _atoi - Function convert string to int
 * @s: Params
 * Return: 0
 */
int _atoi(char *s)
{
	int i, sn = 1, fg = 0, func_output;
	unsigned int ret = 0;

	for (i = 0; s[i] != '\0' && fg != 2; i++)
	{
		if (s[i] == '-')
			sn *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			fg = 1;
			ret *= 10;
			ret += (s[i] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}
	if (sn == -1)
		func_output = -ret;
	else
		func_output = ret;
	return (func_output);
}

/**
 * _isalpha - Funtion tha get alphabet char
 * @c: Params
 * Return: 1 OR 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * intsatty - Function that checks shell interactivity
 * @i: Params
 * Return: 1 OR 0;
 */
int intsatty(info_t *i)
{
	return (isatty(STDIN_FILENO) && i->readfd <= 2);
}
/**
 * _isdelim - Function that checks delimeter
 * @c: Params
 * @delim: Params
 * Return: 1 OR 0
 */
int _isdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
