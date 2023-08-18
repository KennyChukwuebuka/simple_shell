#include "main.h"
/**
 * cust_setenv - Function to set environment
 * @info: Params
 * Return: 0
 */
int cust_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_erputs("Not correct arguement\n");
		return (1);
	}
	if (_cust_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _cust_setenv - Function that set or modify environment
 * @info: params
 * @ar: Params
 * @val: Params
 * Return: 0
 */
int _cust_setenv(info_t *info, char *ar, char *val)
{
	char *buff = NULL;
	list_t *node;
	char *pa;

	if (!ar || !val)
		return (0);
	buff = malloc(_strlen(ar) + _strlen(val) + 2);
	if (!buff)
		return (1);
	str_cpy(buff, ar);
	_strcat(buff, "=");
	_strcat(buff, val);
	node = info->env;
	while (node)
	{
		pa = _startwith(node->str, ar);
		if (pa && *pa == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	addnodeto_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
/**
 * cust_un_setenv - Function remove env variables
 * @info Params
 * Return: 0
 */
int cust_un_setenv(info_t *info)
{
	int a; 

	if (info->argc == 1)
	{
		_erputs("There is few arguments\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		cust_unset_env(info, info->argv[a]);
	return (0);
}

