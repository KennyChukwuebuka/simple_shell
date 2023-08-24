#include "main.h"
/**
 * cust_chdir - Function responsible to change current working directory
 * @info: Params
 * Return: 0
 */
int cust_chdir(info_t *info)
{
	char *sp, *dr, buffer[1024];
	int ch_dir;
/*Get the current working directory and store it in 'sp'*/
	sp = getcwd(buffer, 1024);
	if (!sp)
		_puts("GET: >>cwd fail errmsg<<\n");/*Print error message if getcwd fails*/
	if (!info->argv[1])/*If no argument is provided after the command*/
	{ /*Get the value of the "HOME" environment variable*/
		dr = _custgetenv(info, "HOME=");
		if (!dr)
			ch_dir = chdir((dr = _custgetenv(info, "PWD=")) ?
					dr : "/");
		else
			ch_dir = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)/*If the argument is "-"*/
	{
		if (!_custgetenv(info, "OLDPWD="))
		{
			_puts(sp);/*Print the current working directory*/
			_putchar('\n');
			return (1);
		} /*Print the value of OLDPASSWD*/
		_puts(_custgetenv(info, "OLDPWD=")), _putchar('\n');
		ch_dir = chdir((dr = _custgetenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		ch_dir = chdir(info->argv[1]);
	if (ch_dir == -1)/*Check if chdir failed*/
	{
		print_er(info, "I can not cd into ");
		_erputs(info->argv[1]), _erputchar('\n');/*Print an error message*/
	}
	else
	{ /*Set the environment variables OLDPASSWD and PSSWD*/
		_cust_setenv(info, "OLDPWD", _custgetenv(info, "PWD="));
		_cust_setenv(info, "PWD", getcwd(buffer, 1024));/*update PWD with cwd*/
	}
	return (0);/*Success*/
}
/**
 * custhistory_list - Function history command list
 * @info: Params
 * Return: 0
 */
int custhistory_list(info_t *info)
{
	_mylist_print(info->history);
		return (0);
}
/**
 * custsetals - Function to set string als
 * @info: Param
 * @str: Params
 * Return: 0
 */
int custsetals(info_t *info, char *str)
{
	char *a;
/*Find the position of the equal sign in the input string*/
	a = str_chr(str, '=');
	if (!a)/*If equal sign is not found, return 1*/
		return (1);
	if (!*++a)/*if notin after = sign unset alias*/
		return (custunsetals(info, str));
	custunsetals(info, str);/*Unset the alias,add a new node to alias list*/
/*Add a new node to the end of the alias list ret 1 if adding node fail*/
	return (addnodeto_end(&(info->alias), str, 0) == NULL);
}
