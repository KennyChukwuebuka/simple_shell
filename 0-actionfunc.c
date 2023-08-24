#include "main.h"
/**
 * cust_extshell - Function to exit the shell
 * @info: Params
 * Return: 0
*/
int cust_extshell(info_t *info)
{
	int ex;

	if (info->argv[1])/*check if command line arg is provided*/
	{
		ex = _ersatoi(info->argv[1]);/*convert arg to integer*/
		if (ex == -1)/*check if conversion is a success*/
		{ /*if conversion fail, set status, print err msg and return 1*/
			info->status = 2;
			print_er(info, "Illegal number: ");/*condition of return statement*/
			_erputs(info->argv[1]);
			_erputchar('\n');
			return (1);
		} /*update the err number and return -2*/
		info->er_num = _ersatoi(info->argv[1]);
		return (-2);
	}
	info->er_num = -1;/*is no command provided set er to -1 and ret -2*/
	return (-2);
}
/**
 * cust_helpcd - Function change curr dir
 * @info: Params
 * Return: 0
 */
int cust_helpcd(info_t *info)
{
	char **ar;/*declare a char pointer to an arr of str*/

	ar = info->argv;/*assign value of info->argv(com_line arg arr) to ar*/
	_puts("custom help is working \n");/*print message to tell is working*/

	if (0)/*check if cond is 0 (just for demo)*/
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

	a = str_chr(str, '=');/*find the first occ of '=' in str*/

	if (!a)/*if not found ret 1 indicating a failure*/
		return (1);
	b = *a;/*store char in position a in the var b*/
	*a = 0;
	res = del_node_i(&(info->alias), custgetnode_ind(info->alias,
				custnodestart_with(info->alias, str, -1)));
	*a = b;/*restore original char at positon a*/
	return (res);
}

