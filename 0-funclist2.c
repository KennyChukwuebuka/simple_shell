#include "main.h"
/**
 * _tolistlen - Function to get len of linkedlist
 * @j: Params
 * Return: list size
 */
size_t _tolistlen(const list_t *j)
{
	size_t i = 0;

	while (j)
	{
		j = j->next;
		i++;
	}
	return (i);
}
/**
 * _mylist_print - Function prints all list link ele
 * @j: Params
 * Return: list size
 */
size_t _mylist_print(const list_t *j)
{
	size_t i = 0;

	while (j)
	{
		_puts(conv_num(j->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(j->str ? j->str : "(nil)");
		_puts("\n");
		j = j->next;
		i++;
	}
	return (i);
}
/**
 * custgetnode_ind - Function get node index
 * @head: Params
 * @node: Params
 * Return: index
 */
ssize_t custgetnode_ind(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);

}
