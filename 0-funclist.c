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
	{ /*print str stored in current node if it exit or print nil is not exist*/
		_puts(j->str ? j->str : "(nil)");
		_puts("\n");
		j = j->next;/*move to the next node in linked list*/
		i++;/*increment counter for nmber of nodes*/
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
	list_t *n_node, *node;/*declare ptrs to lis_t*/
/*check if the head pointer is null*/
	if (!head)
		return (NULL);

	node = *head;/*assign the head node to the node pointer*/
	n_node = malloc(sizeof(list_t));/*mem alloc for new node*/
	if (!n_node)
		return (NULL);/*return null if mem alloc fails*/
	cust_memset((void *)n_node, 0, sizeof(list_t));/*initialize new mem*/
	n_node->num = num;/*set the num field of the new node*/
	if (str)
	{
		n_node->str = str_dup(str);/*dup input str and store in the new node*/
		if (!n_node->str)
		{
			free(n_node);/*free alloc mem for the new node*/
			return (NULL);/*return null if str dup fails*/
		}
	}
	if (node)/*if the list is not empty node is not null*/
	{
		while (node->next)/*go through the list to find last node*/
			node = node->next;
		node->next = n_node;/*assign new node as next of the last node*/
	}
	else
		*head = n_node;/*if list is empty assign new node as head of list*/
	return (n_node);/*return new added node*/
}
/**
 * del_node_i - Function that del node at the ind
 * @head: Params
 * @ind: Params
 * Return: 1 or 0
 */
int del_node_i(list_t **head, unsigned int ind)
{
	list_t *node, *pr_node;/*declare pointers to list node*/
	unsigned int i = 0;/*set counter*/

	if (!head || !*head)/*if head pointer or list is null*/
		return (0);/*return 0*/

	if (!ind)/*if the index is 0 delete the head node*/
	{
		node = *head;/*store the current head node*/
		*head = (*head)->next;/*update the head ptr to next node*/
		free(node->str);
		free(node);
		return (1);
	} /*traverse the list*/
	node = *head;
	while (node)
	{
		if (i == ind)
		{ /*link previous node to the next node*/
			pr_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;/*increment the index counter*/
		pr_node = node;/*store current node as previous node*/
		node = node->next;/*move to the next*/
	}
	return (0);/*if index is out of bound ret 0*/
}

