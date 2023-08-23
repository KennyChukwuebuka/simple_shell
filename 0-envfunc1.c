#include "main.h"
/**
 * cust_setenv - Function to set environment
 * @info: Params
 * Return: 0 OR 1
 */
int cust_setenv(info_t *info)
{
	if (info->argc != 3)/*check if the number cmd-line arg is not 3*/
	{
		_erputs("Not correct arguement\n");
		return (1); /*ret 1 to indicate a failure*/
	} /*cal my custome func to set the env variable*/
	if (_cust_setenv(info, info->argv[1], info->argv[2]))
		return (0); /*ret 0 to indicate a suceess*/
	return (1); /*ret 1 to indicate a fail*/
}
/**
 * _cust_setenv - Function that set environment variable within
 * custom data structure
 * @info: params
 * @ar: Params
 * @val: Params
 * Return: 0
 */
int _cust_setenv(info_t *info, char *ar, char *val)
{
	char *buff = NULL;
	list_t *node;
	char *pa;

	if (!ar || !val)/*check condition is any is missing*/
		return (0);/*return  0 indicate failure*/
	buff = malloc(_strlen(ar) + _strlen(val) + 2);/*alloc mem for buffer*/
	if (!buff)
		return (1); /*ret 1 to indicate failure*/
	str_cpy(buff, ar); /*copy arg name to buffer*/
	_strcat(buff, "=");/*concat '=' to buff*/
	_strcat(buff, val);/*concat val to buff*/
	node = info->env;
	while (node)/*iterate through llist of env variable*/
	{
		pa = _startwith(node->str, ar);/*check matches*/
		if (pa && *pa == '=')/*if match found */
		{
			free(node->str);/*free mem occupied by exiting variable*/
			node->str = buff;/*set varibale str to new buff*/
			info->env_changed = 1;
			return (0);/*return 0 to indicate success*/
		}
		node = node->next;
	}
	addnodeto_end(&(info->env), buff, 0);/*if variable no exist add new node*/
	free(buff);
	info->env_changed = 1;
	return (0);/*ret 0 to indicate success*/
}
/**
 * cust_un_setenv - Function remove env variables
 * @info: Params
 * Return: 0
 */
int cust_un_setenv(info_t *info)
{
	int a;

	if (info->argc == 1)/*check if cmd arg is exactly 1*/
	{
		_erputs("There is few arguments\n");
		return (1);/*return 1 to indicate failure*/
	}
	for (a = 1; a <= info->argc; a++)/*loop through cmd line from index*/
		cust_unset_env(info, info->argv[a]);/*unset env variable*/
	return (0);/*return 0 on success*/
}

