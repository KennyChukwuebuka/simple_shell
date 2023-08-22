#include "main.h"
/**
 * cust_histfile - Function that collect history of file event
 * @info: Params
 * Return: str
 */
char *cust_histfile(info_t *info)
{
	char *buff, *dr;

	dr = _custgetenv(info, "HOME=");
	if (!dr)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	str_cpy(buff, dr);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}
/**
 * cust_wrthist - Function that append to a file
 * @info: Params
 * Return: 1 OR -1
 */
int cust_wrthist(info_t *info)
{
	ssize_t fdesc;
	char *f_name = cust_histfile(info);
	list_t *node = NULL;

	if (!f_name)
		return (-1);

	fdesc = open(f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_name);
	if (fdesc == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putstrfd(node->str, fdesc);
		_putcfd('\n', fdesc);
	}
	_putcfd(BUF_FLUSH, fdesc);
	close(fdesc);
	return (1);
}
