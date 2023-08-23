#include "main.h"
/**
 * custreadhst - Function that read and process the content
 * of a history file
 * @info: Params
 * Return: 0
 */
int custreadhst(info_t *info)
{
	int i, lasthst = 0, line = 0;
	ssize_t fdesc, len, f_size = 0;
	struct stat fst;
	char *buff = NULL, *f_name = cust_histfile(info);

	if (!f_name)/*check is history file name is unavailable*/
		return (0);
	fdesc = open(f_name, O_RDONLY);/*open hist file for reading*/
	free(f_name);/*free mem alloc for hist filename*/
	if (fdesc == -1)/*check is opening the file failed*/
		return (0);
	if (!fstat(fdesc, &fst))/*retrieve file status infomation*/
		f_size = fst.st_size;
	if (f_size < 2)/*if file size less that 2 byte ret 0*/
		return (0);
	buff = malloc(sizeof(char) * (f_size + 1));/*alloc mem to read file cont*/
	if (!buff)/*check if mem alloc failed*/
		return (0);
	len = read(fdesc, buff, f_size);/*read content of file into buffer*/
	buff[f_size] = 0;
	if (len <= 0)/*if read opr fail or ret no byte ret 0 after free*/
		return (free(buff), 0);
	close(fdesc);/*close the history file*/
	for (i = 0; i < f_size; i++)/*process each chr in buf and split content*/
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			custbhist(info, buff + lasthst, line++);
			lasthst = i + 1;
		}
	if (lasthst != i)/*if there are reminaing char after loop process*/
		custbhist(info, buff + lasthst, line++);
			free(buff);/*free the buff*/
			info->histcount = line;/*update the history count in the info sruct*/
			while (info->histcount-- >= HIST_MAX)/*trim hist list to not exced max*/
				del_node_i(&(info->history), 0);
			custre_numhst(info);/*re number history entries*/
			return (info->histcount);/*return updated history count*/
}
/**
 * custbhist - Function to add entry to list
 * @info: Params
 * @buff: Params
 * @c: Params
 * Return: 0
 */
int custbhist(info_t *info, char *buff, int c)
{
	list_t *node = NULL;

	if (info->history)/*check if history list is not empty*/
		node = info->history;/*if not empty assign to node*/
	addnodeto_end(&node, buff, c);/*add a new node with the buff and c*/

	if (!info->history)/*if list was empty update info structure*/
		info->history = node;
	return (0);/*success ret 0*/
}
/**
 * custre_numhst - Function that re_number history entries
 * in a linked list
 * @info: Params
 * Return: hist
 */
int custre_numhst(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)/*iterate through hist list*/
	{
		node->num = i++;/*assign val i to the num member of history list*/
		node = node->next;/*move to next node in the l-list*/
	}
	/*update histcount member in the info struct with final value */
	/*return the updated value*/
	return (info->histcount = i);
}
