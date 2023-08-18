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
 */
