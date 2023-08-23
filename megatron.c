#include "main.h"
/**
 * megatron - Function command dispatcher
 * @info: Params
 * Return: num
 */

int megatron(info_t *info)
{
	int i, ret_mega = -1;
	/*Declare an arr of structure tht contains a comand str and its function.*/
	mega_table mega[] = {
		{"env", _custenv},
		{"setenv", cust_setenv},
		{"unsetenv", cust_un_setenv},
		{"exit", cust_extshell},
		{"cd", cust_chdir},
		{"help", cust_helpcd},
		{"history", custhistory_list},
		{"alias", cust_als},
		{NULL, NULL} /*end of the arr*/
	};

	for (i = 0; mega[i].type; i++)/*iterate through arr*/
		if (_strcmp(info->argv[0], mega[i].type) == 0)/*compare command*/
		{
			info->line_count++;/*increment line count into info structure*/
			ret_mega = mega[i].func(info);/*call matching n store return value*/
			break;/*exit loop ater findng match*/
		}
	return (ret_mega);/*return the ret value of asoc function*/
}
