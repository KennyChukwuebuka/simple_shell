#include "main.h"
/**
 * cust_histfile - Function that collect history of file event
 * @info: Params
 * Return: str
 */
char *cust_histfile(info_t *info)
{
	char *buff, *dr;/*declare two char ptr*/
/*Retrieve the value of the environment var HOME*/
	dr = _custgetenv(info, "HOME=");/*using the custome macro _cutgetenv*/
	if (!dr)/*check if HOME is not available*/
		return (NULL);/*if it is not available ret NULL*/
		/*alloc memory for buff, considering len of HIST_FILE & HOME*/
	buff = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
	if (!buff)/*check if mem was successful*/
		return (NULL);/*if it fails return NULL*/
	buff[0] = 0;/*initializ first cahr of buff*/
	str_cpy(buff, dr);/*copy content of HOME to buffer*/
	_strcat(buff, "/");/*concat '/' char to buffer*/
	_strcat(buff, HIST_FILE);/*concat HIST_FILE to buffer*/
	return (buff);/*return buffer containing full path of hist*/
}
/**
 * cust_wrthist - Function that write content of history list
 * to a file
 * @info: Params
 * Return: 1 OR -1
 */
int cust_wrthist(info_t *info)
{
	ssize_t fdesc;/*Declare a file descriptor of type ssize_t*/
	char *f_name = cust_histfile(info);/*using function get file name*/
	list_t *node = NULL;/*declare ptr to list_t struct set to NULL*/

	if (!f_name)/*check if history file name is not available*/
		return (-1);/*if hist filename not available return -1 (failure)*/
/*open the history file with specific flags. file perm is set to 0664*/
	fdesc = open(f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_name);/*free mem allocatated to the hist file name*/
	if (fdesc == -1)/*chck if fdesc is error while opening*/
		return (-1);/*if openig file fail return -1*/
		/*loop through and the hist linked list and wrt each node str to hist file*/
	for (node = info->history; node; node = node->next)
	{ /*write the string to the current node followed by a new line*/
		_putstrfd(node->str, fdesc);
		_putcfd('\n', fdesc);
	}
	/*flush the internal buff to the file desc using BUF_FLUSH*/
	_putcfd(BUF_FLUSH, fdesc);
	close(fdesc);/*close the hist file*/
	return (1);/*return 1 success*/
}
