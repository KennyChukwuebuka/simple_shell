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
 * custrepvars - Function that replace vars in tok string
 * @info: Params
 * Return: 1 OR 0
 */
int custrepvars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			_repstr(&(info->argv[i]), str_dup(conv_num(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			_repstr(&(info->argv[i]), str_dup(conv_num(getpid(), 10, 0)));
			continue;
		}
		node = custnodestart_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			_repstr(&(info->argv[i]), str_dup(str_chr(node->str, '=') + 1));
			continue;
		}
		_repstr(&info->argv[i], str_dup(""));
	}
	return (0);
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
