#include "main.h"
/**
 * _erputchar - Function that writes char to error
 * @c: Params
 * Return: 1 OR -1
 */
int _erputchar(char c)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{ /*Write the buffer contents to the standard error output*/
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
/*Chk if the char is a special char (BUF_FLUSH) or if the buf is full*/
/*If so, wrt the content of d buf to d file desc and reset the counta 'i'*/
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buff, i);/*wrt buf content to fdesd*/
		i = 0;/*reset buf position counter*/
	}
	/*If the character is not a special character (BUF_FLUSH),*/
	/*add the char to the buf and incre the buf positn counter 'i'*/
	if (c != BUF_FLUSH)
	{
		buff[i] = c;/*add character to buf*/
		i++;/*increment buf position counter*/
	}
	return (1);/*Success*/
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

	if (info->argc == 1)/*check if one argument is provided*/
	{ /*iterate through th alias list and find the function*/
		node = info->alias;
		while (node)
		{
			custprtals(node);/*print the alias node*/
			node = node->next;
		}
		return (0);/*Return on success*/
	}
	for (i = 1; info->argv[i]; i++)/*loop through command line argument*/
	{
		a = str_chr(info->argv[i], '=');/*find '=' in the argument*/
		if (a)/*if '=' is found set an alias*/
			custsetals(info, info->argv[i]);
		else /*find node in alias list starting with cur arg and contain =*/
			custprtals(custnodestart_with(info->alias, info->argv[i], '='));
	}
	return (0);/*return sucess*/
}
