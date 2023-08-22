#include "main.h"
/**
 * cust_chdir - Function to change dir
 * @info: Params
 * Return: 0
 */
int cust_chdir(info_t *info)
{
	char *sp, *dr, buffer[1024];
	int ch_dir;

	sp = getcwd(buffer, 1024);
	if (!sp)
		_puts("GET: >>cwd fail errmsg<<\n");
	if (!info->argv[1])
	{
		dr = _custgetenv(info, "HOME=");
		if (!dr)
			ch_dir = chdir((dr = _custgetenv(info, "PSSWD=")) ?
					dr : "/");
		else
			ch_dir = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_custgetenv(info, "OLDPASSWD="))
		{
			_puts(sp);
			_putchar('\n');
			return (1);
		}
		_puts(_custgetenv(info, "OLDPASSWD=")), _putchar('\n');
		ch_dir = chdir((dr = _custgetenv(info, "OLDPASSWD=")) ? dr : "/");
	}
	else
		ch_dir = chdir(info->argv[1]);
	if (ch_dir == -1)
	{
		print_er(info, "I can not cd into ");
		_erputs(info->argv[1]), _erputchar('\n');
	}
	else
	{
		_cust_setenv(info, "OLDPASSWD", _custgetenv(info, "PSSWD="));
		_cust_setenv(info, "PSSWD", getcwd(buffer, 1024));
	}
	return (0);

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

	a = str_chr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (custunsetals(info, str));
	custunsetals(info, str);
	return (addnodeto_end(&(info->alias), str, 0) == NULL);
}
