#include "main.h"
/**
 * rp_com - Function that is used to remove comment from a string
 * where a commment is defined as any '#' character
 * @buf: Params
 * Return: 0
 */
void rp_com(char *buf)
{
	int i;
/*Iterate through the char of the str until a null termin is reached*/
	for (i = 0; buf[i] != '\0'; i++)
	{/*Chk if cur char is '#' and if it either d fst char or has ' '*/
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{/*Replc the '#' char with a null termi to truncate the string*/
			buf[i] = '\0';
			break;/*exit loop*/
		}
	}
}
/**
 * _ersatoi - Function convert string to int
 * @s: Params
 * Return: 1 OR 0
 */
int _ersatoi(char *s)
{
	int i = 0;
	unsigned long int res = 0;

	if (*s == '+')/*check if it isa + sign*/
		s++;/*move the ptr foward and skip + sign*/

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * _printd - Function print a dec
 * @input: Params
 * @fd: Params
 * Return: char
 */
int _printd(int input, int fd)
{
	int (*_pchar)(char) = _putchar;
	int i, co = 0;
	unsigned int _abs, cur;

	if (fd == STDERR_FILENO)
		_pchar = _erputchar;
	if (input < 0)
	{
		_abs = -input;
		_pchar('-');
		co++;
	}
	else
		_abs = input;
	cur = _abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs / i)
		{
			_pchar('0' + cur / i);
			co++;
		}
		cur %= i;
	}
	_pchar('0' + cur);
	co++;

	return (co);
}
/**
 * print_er - Function that print the error msg
 * @i: Params
 * @estr: Params
 * Return: 0 OR 1
 */
void print_er(info_t *i, char *estr)
{
	_erputs(i->fname);
	_erputs(": ");
	_printd(i->line_count, STDERR_FILENO);
	_erputs(": ");
	_erputs(i->argv[0]);
	_erputs(": ");
	_erputs(estr);
}
/**
 * conv_num - Function converter
 * @num: Params
 * @base: Params
 * @flg: Params
 * Return: string
 */
char *conv_num(long int num, int base, int flg)
{
	static char *array;
	static char buffer[50];
	char sgn = 0;
	char *ptr;
	unsigned long i = num;

	if (!(flg & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		sgn = '-';
	}
	array = flg & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[i % base];
		i /= base;
	} while (i != 0);

	if (sgn)
		*--ptr = sgn;
	return (ptr);
}
