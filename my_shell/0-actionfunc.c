#include "main.h"
/**
 * cust_extshell - Function to exit the shell
 * @info: Params
 * Return: 0
*/
int cust_extshell(info_t *info)
{
	int ex;

	if (info->argv[1])
	{
		ex = _ersatoi(info->argv[1]);
		if (ex == -1)
		{
			info->status = 2;
			print_er(info, "number is not legal: ");
			_erputs(info->argv[1]);
			_erputchar('\n');
			return (1);
		}
		info->er_num = _ersatoi(info->argv[1]);
		return (-2);
	}
	info->er_num = -1;
	return (-2);
}
/**
 * cust_helpcd - Function change curr dir
 * @info: Params
 * Return: 0
 */
int cust_helpcd(info_t *info)
{
	char **ar;

	ar = info->argv;
	_puts("custom help is working \n");

	if (0)
		_puts(*ar);
	return (0);
}
/**
 * custunsetals - Function to set alias
 * @str: Params
 * @info: Params
 * Return: 0
 */
int custunsetals(info_t *info, char *str)
{
	char *a, b;
	int res;

	a = str_chr(str, '=');

	if (!a)
		return (1);
	b = *a;
	*a = 0;
	res = del_node_i(&(info->alias), custgetnode_ind(info->alias,
				custnodestart_with(info->alias, str, -1)));
	*a = b;
	return (res);
}

