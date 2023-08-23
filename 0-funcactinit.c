#include "main.h"
/**
 * custprtals - Function that prints str als
 * @node: Params
 * Return: 0
 */
int custprtals(list_t *node)
{
	char *a = NULL, *b = NULL;

	if (node)
	{
		a = str_chr(node->str, '=');
		for (b = node->str; b <= a; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * st_info_clear - Function to set at intial state
 * @info: Params
 * Return: nothing
 */
void st_info_clear(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * custrepals - Function to replace als tok str
 * @info: Params
 * Return: 1 OR 0
 */
int custrepals(info_t *info)
{
	int i;
	list_t *node;
	char *s;

	for (i = 0; i < 10; i++)
	{
		node = custnodestart_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		s = str_chr(node->str, '=');
		if (!s)
			return (0);
		s = str_dup(s + 1);
		if (!s)
			return (0);
	       info->argv[0] = s;
	}
	return (1);
}
/**
 * custrepvars - Function that performs variable replacement in
 * an arry of string replc patterns with corresponding values
 * @info: Params
 * Return: 1 OR 0
 */
int custrepvars(info_t *info)
{
	int i = 0;
	list_t *node;
/*Loop through each argument in the inf0->argv array*/
	for (i = 0; info->argv[i]; i++)
	{/*Check if the argument doesn't start with '$' or is empty.*/
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;/*skip to next if iteration is true*/
		if (!_strcmp(info->argv[i], "$?"))/*check is argument is $*/
		{/*Replace it with the exit status converted to a string*/
			_repstr(&(info->argv[i]), str_dup(conv_num(info->status, 10, 0)));
			continue;/*continue to next iteration*/
		}
		if (!_strcmp(info->argv[i], "$$"))/*check is argumt is $$*/
		{/*Replace it with the process ID converted to a string.*/
			_repstr(&(info->argv[i]), str_dup(conv_num(getpid(), 10, 0)));
			continue;/*contiune to next iteration*/
		} /*Search for an environment variable in the custnodestart_with list*/
		node = custnodestart_with(info->env, &info->argv[i][1], '=');
		if (node)
		{/*Replc the argumt wt the value of the found environment var*/
			_repstr(&(info->argv[i]), str_dup(str_chr(node->str, '=') + 1));
			continue;/*continue to next iteration*/
		} /*If no match is found, replace the argumt wt an empty str*/
		_repstr(&info->argv[i], str_dup(""));
	}
	return (0);/*Return 0 to indicate successful execution*/
}
/**
 * _repstr - Function replace str
 * @o_str: Params
 * @n_str: Params
 * Return: 1 OR 0
 */
int _repstr(char **o_str, char *n_str)
{
	free(*o_str);
	*o_str = n_str;
	return (1);
}
