#include "main.h"

/**
 * _putchar - Function that write character
 * @c: Params
 * Return: 1 OR -1
 */
int _putchar(char c)
{
	static int init;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || init >= WRITE_BUF_SIZE)
	{
		write(1, buf, init);
		init = 0;
	}
	if (c != BUF_FLUSH)
		buf[init++] = c;
	return (1);
}
/**
 * _puts - Function that prints str
 * @s: Params
 * Return Nothing
 */
void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
			i++;
	}
}
/**
 * str_cpy - Function that copy string
 * @des: Params
 * @src: Params
 * Return: Dest
 */
char *str_cpy(char *des, char *src)
{
	int init = 0;

	if (des == src || src == 0)
		return (des);
	while (src[init])
	{
		des[init] = src[init];
		init++;
	}
	des[init] = 0;
	return (des);
}
/**
 * str_dup - Function that duplicate string
 * @str: Params
 * Return: Str
 */
char *str_dup(const char *str)
{
	int len = 0;
	char *result;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	for (len++; len--;)
		result[len] = *--str;
	return (result);
}
