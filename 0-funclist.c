#include "main.h"
/**
 * prt_liststr - Function that print str ele
 * @j: Param
 * Return: list
 */
size_t prt_liststr(const list_t *j)
{
	size_t i = 0;

	while (j)
	{
		_puts(j->str ? j->str : "(nil)");
		_puts("\n");
		j = j->next;
		i++;
	}
	return (i);
}
/**
 * addnodeto_end - Function add node to end
 * @head: Params
 * @str: Params
 * @num: Params
 * Return: list
 */
list_t *addnodeto_end(list_t **head, const char *str, int num)
{
	list_t *n_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	n_node = malloc(sizeof(list_t));
	if (!n_node)
		return (NULL);
	cust_memset((void *)n_node, 0, sizeof(list_t));
	n_node->num = num;
	if (str)
	{
		n_node->str = str_dup(str);
		if (!n_node->str)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	else
		*head = n_node;
	return (n_node);
}
/**
 * del_node_i - Function that del node at the ind
 * @head: Params
 * @ind: Params
 * Return: 1 or 0
 */
int del_node_i(list_t **head, unsigned int ind)
{
	list_t *node, *pr_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!ind)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == ind)
		{
			pr_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		pr_node = node;
		node = node->next;
	}
	return (0);
}

