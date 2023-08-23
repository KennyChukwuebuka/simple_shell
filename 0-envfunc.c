#include "main.h"
/**
 * _custenv - Function designed to print content of a linked iist
 * that is sotred in env variable
 * @info: Params
 * Return: 0
 */
int _custenv(info_t *info)
{ /*print the content of a linked list "env" as str*/
	prt_liststr(info->env);
	return (0);/*return 0 to ind success*/
}

/**
 * _custgetenv - Function that search through a linkedlist of env var
 * and return the val of the first env variable that matches the provided
 * name
 * @info: Params
 * @name: Param
 * Return: val
 */
char *_custgetenv(info_t *info, const char *name)
{ /*initialize a ptr to the linked list of env variable*/
	list_t *node = info->env;
	char *p; /*declare a char pointer to store result*/

	while (node) /*loop through the linked list of env variable*/
	{
		p = _startwith(node->str, name);/*check if cur env variable start with name*/
		if (p && *p)/*if p is not NULL & first char p is not '\0'*/
			return (p);/*return p*/
		node = node->next;/*move to next node in linked list*/
	}
	return (NULL);/*return NULL if env variable with name not found*/
}
/**
 * cust_unset_env - Function that removes env variable from a linked list
 * of env variable variable that matches specific prefix "va" followed by "="
 * @info: Params
 * @va: Param
 * Return: 1 0R 0
 */
int cust_unset_env(info_t *info, char *va)
{ /*initialize a ptr to the linked list of env variable*/
	list_t *node = info->env;
	size_t i = 0;/*initialize a counter for index of current node*/
	char *pa;/*initialize char ptr to stor temp res*/

	if (!node || !va)/*check if node or va is null, if so ret 0*/
		return (0);

	while (node)/*loop through liked list of env variable*/
	{
		pa = _startwith(node->str, va);/*check if current env var start with va*/
		if (pa && *pa == '=')/*is pa is not NULL &first char pa is "=" mean match*/
		{
			info->env_changed = del_node_i(&(info->env), i);/*del cur node fr llist*/
			i = 0;/*resest counter i to 0*/
			node = info->env;/*rest ptr node to begining of llist*/
			continue;/*continue to next itteraion of loop*/
		}
		node = node->next;/*move to the next node of linked list */
		i++;/*increment the counter*/
	}
	return (info->env_changed);/*ret val on env_changed indictn if val changed*/
}
