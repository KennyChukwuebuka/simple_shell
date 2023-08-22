#include "main.h"
/**
 * megatron - Function
 * @info: Params
 * Return: num
 */

int megatron(info_t *info)
{
	int i, ret_mega = -1;
	mega_table mega[] = {
		{"env", _custenv},
		{"setenv", cust_setenv},
		{"unsetenv", cust_un_setenv},
		{"exit", cust_extshell},
		{"cd", cust_chdir},
		{"help", cust_helpcd},
		{"history", custhistory_list},
		{"alias", cust_als},
		{NULL, NULL}
	};

	for (i = 0; mega[i].type; i++)
		if (_strcmp(info->argv[0], mega[i].type) == 0)
		{
			info->line_count++;
			ret_mega = mega[i].func(info);
			break;
		}
	return (ret_mega);
}
