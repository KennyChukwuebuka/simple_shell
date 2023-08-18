#include "main.h"

/**
 * _custgetenviron - Function return cpy of environment
 * @info: Params
 * Return: 0
 */
char **_custgetenviron(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = customlist_tostring(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}
/**
 * custpopenv_list - Function that pop list
 * @info: Params
 * Return: 0
 */
int custpopenv_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addnodeto_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}


