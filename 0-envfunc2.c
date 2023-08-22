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
/**
 * isfile_cmd - Function to check exec file
 * @info: Params
 * @p: Params
 * Return: 1 OR 0
 */
int isfile_cmd(info_t *info, char *p)
{
	struct stat fst;

	(void)info;
	if (!p || stat(p, &fst))
		return (0);
	if (fst.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * characdup - Function that dup chars
 * @pstr: Params
 * @st: Params
 * @end: Params
 * Return: ptr
 */
char *characdup(char *pstr, int st, int end)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0, i = st; i < end; i++)
		if (pstr[i] != ':')
			buf[j++] = pstr[i];
	buf[j] = 0;
	return (buf);
}
/**
 * custfindpath - Function that finds path of str
 * @info: Params
 * @pstr: Params
 * @c: Params
 * Return: path
 */
char *custfindpath(info_t *info, char *pstr, char *c)
{
	int i = 0, c_pos = 0;
	char *p;

	if (!pstr)
		return (NULL);
	if ((_strlen(c) > 2) && _startwith(c, "./"))
	{
		if (isfile_cmd(info, c))
			return (c);
	}
	while (1)
	{
		if (!pstr[i] || pstr[i] == ':')
		{
			p = characdup(pstr, c_pos, i);
			if (!*p)
				_strcat(p, c);
			else
			{
				_strcat(p, "/");
				_strcat(p, c);
			}
			if (isfile_cmd(info, p))
				return (p);
			if (!pstr[i])
				break;
			c_pos = i;
		}
		i++;
	}
	return (NULL);
}

