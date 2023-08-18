#include "main.h"
/**
 * list_free - Function that frees all the node
 * @ptr_tohead: Params
 *Return: nothing
 */
void list_free(list_t **ptr_tohead)
{
	list_t *node, *node_tonext, *head;

	if (!ptr_tohead || !*ptr_tohead)
		return;
	head = *ptr_tohead;
	node = head;
	while (node)
	{
		node_tonext = node->next;
		free(node->str);
		free(node);
		node = node_tonext;
	}
	*ptr_tohead = NULL;
}
/**
 * _myaddnode - Function that add node
 * @head: Params
 * @num: Params
 * @str: Params
 * Return: Returns a list size
 */
list_t *_myaddnode(list_t **head, const char *str, int num)
{
	list_t *new_listhead;

	if (!head)
		return (NULL);
	new_listhead = malloc(sizeof(list_t));
	if (!new_listhead)
		return (NULL);
	cust_memset((void *)new_listhead, 0, sizeof(list_t));
	new_listhead->num = num;
	if (str)
	{
		new_listhead->str = str_dup(str);
		if (new_listhead->str)
		{
			free(new_listhead);
			return (NULL);
		}
	}
	new_listhead->next = *head;
	*head = new_listhead;
	return (new_listhead);
}
