#include "main.h"
/**
 * custsignal - Function signal
 * @sig: Params
 * Return: void
 */
void custsignal(__attribute__((unused))int sig)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
/**
 * custinp_buf - Function that reads inpput from user
 * @info: Params
 * @buff: Params
 * @c: Params
 * Return: bytes
 */
ssize_t custinp_buf(info_t *info, char **buff, size_t *c)
{
	ssize_t rd = 0;
	size_t len = 0;

	if (!*c) /*check if input buffer is empty*/
	{
		free(*buff);/*free existing buffer*/
		*buff = NULL;
		signal(SIGINT, custsignal); /*set custom signal handler (CTRL+C)*/
#if USE_GETLINE/*Depending on USE_GETLINE macro, read input using getline*/
		rd = getline(buff, &len, stdin);
#else
		rd = cust_getline(info, buff, &len);/*Or read using my custom getline*/
#endif
		if (rd > 0)/*if input is successful read*/
		{
			if ((*buff)[rd - 1] == '\n')
			{
				(*buff)[rd - 1] = '\0';
				rd--;
			}
			info->linecount_flag = 1;/*set flag indicating line is read*/
			rp_com(*buff);
			custbhist(info, *buff, info->histcount++);/*store input in buffer*/
			{/*update the char count in input bufa and store the bufa ptr in info*/
				*c = rd;
				info->cmd_buf = buff;
			}
		}
	}
	return (rd);/*return number of char read*/
}
