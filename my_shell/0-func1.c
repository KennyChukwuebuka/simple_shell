#include "main.h"
/**
 * _erputchar - Function that writes char to err
 * @c: Params
 * Return: 1 OR -1
 */
int _erputchar(char c)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buff[i] = c;
		i++;
	}
	return (1);
}
/**
 * _erputs - Function that prints string
 * @str: Params
 * Return: Nothing
 */
void _erputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_erputchar(str[i]);
		i++;
	}
}
/**
 * _putstrfd - Function that prints string to fd
 * @str: Params
 * @fd: Params
 * Return: characters
 */
int _putstrfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putcfd(*str++, fd);
	}
	return (i);
}
/**
 * _putcfd - Function puts char to fd
 * @c: Params
 * @fd: Params
 * Return: 1 OR -1
 */
int _putcfd(char c, int fd)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buff, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buff[i] = c;
		i++;
	}
	return (1);
}
/**
 * cust_als - Function alias
 * @info: Params
 * Return: 0
 */
int cust_als(info_t *info)
{
	int i = 0;
	char *a = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			custprtals(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		a = str_chr(info->argv[i], '=');
		if (a)
			custsetals(info, info->argv[i]);
		else
			custprtals(custnodestart_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
