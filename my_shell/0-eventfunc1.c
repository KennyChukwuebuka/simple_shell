#include "main.h"
/**
 * custreadhst - Function that read file history
 * @info: Params
 * Return: 0
 */
int custreadhst(info_t *info)
{
	int i, lasthst = 0, line = 0;
	ssize_t fdesc, len, f_size = 0;
	struct stat fst;
	char *buff = NULL, *f_name = cust_histfile(info);

	if (!f_name)
		return (0);
	fdesc = open(f_name, O_RDONLY);
	free(f_name);
	if (fdesc == -1)
		return (0);
	if (!fstat(fdesc, &fst))
		f_size = fst.st_size;
	if (f_size < 2)
		return (0);
	buff = malloc(sizeof(char) * (f_size + 1));
	if (!buff)
		return (0);
	len = read(fdesc, buff, f_size);
	buff[f_size] = 0;
	if (len <= 0)
		return (free(buff), 0);
	close(fdesc);
	for (i = 0; i < f_size; i++)
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			custbhist(info, buff + lasthst, line++);
			lasthst = i + 1;
		}
	if (lasthst != i)
		custbhist(info, buff + lasthst, line++);
			free(buff);
			info->histcount = line;
			while (info->histcount-- >= HIST_MAX)
				del_node_i(&(info->history), 0);
			custre_numhst(info);
			return (info->histcount);
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

	if (info->history)
		node = info->history;
	addnodeto_end(&node, buff, c);

	if (!info->history)
		info->history = node;
	return (0);
}
/**
 * custre_numhst - Function that re_number list
 * @info: Params
 * Return: hist
 */
int custre_numhst(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
