#include "main.h"
/**
 * _custenv - Function that print env
 * @info: Params
 * Return: 0
 */
int _custenv(info_t *info)
{
	prt_liststr(info->env);
	return (0);
}

/**
 * _custgetenv - env var
 * @info: Params
 * @name: Param
 * Return: val
 */
char *_custgetenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = _startwith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * cust_unset_env - Function that unset env var
 * @info: Params
 * @va: Param
 * Return: 1 0R 0
 */
int cust_unset_env(info_t *info, char *va)
{
	list_t *node = info->env;
	size_t i = 0;
	char *pa;

	if (!node || !va)
		return (0);

	while (node)
	{
		pa = _startwith(node->str, va);
		if (pa && *pa == '=')
		{
			info->env_changed = del_node_i(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}
