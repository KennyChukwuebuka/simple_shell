#include "main.h"
/**
 * custnodestart_with - Function return starting of node str
 * @node: Params
 * @start: Params
 * @c: Params
 * Return: node OR NULL
 */
list_t *custnodestart_with(list_t *node, char *start, char c)
{
	char *s = NULL;

	while (node)
	{
		s = _startwith(node->str, start);
		if (s && ((c == -1) || (*s == c)))
		return (node);
	node = node->next;
	}
	return (NULL);
}
/**
 * customlist_tostring - Function return arr of str
 * @head: Params
 * Return: str
 */
char **customlist_tostring(list_t *head)
{
	list_t *node = head;
	size_t i = _tolistlen(head), b;
	char **st;
	char *str;

	if (!head || !i)
		return (NULL);
	st = malloc(sizeof(char *) * (i + 1));
	if (!st)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < i; b++)
				free(st[b]);
			free(st);
			return (NULL);
		}
		str = str_cpy(str, node->str);
		st[i] = str;
	}
	st[i] = NULL;
	return (st);
}
/**
 * init_info - Function that initialize struct type info
 * @info: Params
 * @s: Params
 * Return: nothing
 */
void init_info(info_t *info, char **s)
{
	int i = 0;

	info->fname = s[0];
	if (info->arg)
	{
		info->argv = str_tokn(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = str_dup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;
		custrepals(info);
		custrepvars(info);
	}
}
/**
 * _freeinfostrcttype - Function free info_t struct type
 * @info: Params
 * @a: Params
 * Return: nothing
 */
void _freeinfostrcttype(info_t *info, int a)
{
	full_free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (a)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			list_free(&(info->env));
		if (info->history)
			list_free(&(info->history));
		if (info->alias)
			list_free(&(info->alias));
		full_free(info->environ);
			info->environ = NULL;
		custfrees((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
/**
 * custfrees - Function free ptr
 * @ptr: Params
 * Return: nothing
 */
int custfrees(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
