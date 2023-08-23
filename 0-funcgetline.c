#include "main.h"
/**
 * _custreadbuff - Function that reads data from fd into a buffer
 * @info: Params
 * @buf: Params
 * @idn: Params
 * Return: nothing
 */
ssize_t _custreadbuff(info_t *info, char *buf, size_t *idn)
{
	ssize_t red = 0;
/*If there's already data in the buffer (*idn is non-zero), return 0*/
	if (*idn)
		return (0);
/*Read data from the file desc into the buf using READ_BUF_SIZE*/
	red = read(info->readfd, buf, READ_BUF_SIZE);
/*If data is successful update idn with the number of bytes read*/
	if (red >= 0)
		*idn = red;
	return (red);/*return number of bytes read*/
}
/**
 * cust_getline - function reads data from a file descriptor
 * using buffering,finds the next line in the buffer,
 * reallocates memory as needed,and builds a
 * string by copying data from the buffer
 * @info: Params
 * @ptrs: Params
 * @len: Params
 * Return: nothing
 */
int cust_getline(info_t *info, char **ptrs, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, j;
	size_t s;
	ssize_t rd = 0, st = 0;
	char *sp = NULL, *n_sp = NULL, *c;

	sp = *ptrs;/*Initialize pointers and variables*/
	if (sp && len)
		st = *len;
	if (i == j)
		i = j = 0;
	rd = _custreadbuff(info, buf, &j);/*Read data into buffer using function*/
	/*Handle cases where reading fails or no data is available*/
	if (rd == -1 || (rd == 0 && j == 0))
		return (-1);
	/*Find the position of the next newline character*/
	c = str_chr(buf + i, '\n');
	s = c ? 1 + (unsigned int)(c - buf) : j;
	/*Reallocate memory for the string buffer*/
	n_sp = _blockrealloc(sp, st, st ? st + s : s + 1);
	/*Handle memory allocation failure*/
	if (!n_sp)
		return (sp ? free(sp), -1 : -1);
	if (st)/*Copy data from buffer to the string buffer*/
		str_n_cat(n_sp, buf + i, s - i);
	else
		str_n_cpy(n_sp, buf + i, s - i + 1);
	st += s - i;/*Update size and index variables*/
	i = s;
	sp = n_sp;
	if (len)
		*len = st;
	*ptrs = sp;
	return (st);/*Return the number of characters read*/
}
/**
 * _custgetinput - Function that read input from user
 * @info: Params
 * Return: byte
 */
ssize_t _custgetinput(info_t *info)
{
	static char *buff;
	static size_t idx, j, k;
	ssize_t rd = 0;
	char **p = &(info->arg), *s;

	_putchar(BUF_FLUSH);/*Flush any buffered output*/
	/*Read input from user and store in buffer*/
	rd = custinp_buf(info, &buff, &k);
	if (rd == -1)/*Handle reading failure*/
		return (-1);
	if (k)/*If there's input available*/
	{
		j = idx;/*Initialize j with idx*/
		s = buff + idx;/*Point s to a position within the buffer*/
		checkcont_chain(info, buff, &j, idx, k);
		while (j < k)
		{ /*Check if current character is a delimiter in the chain*/
			if (_ischaindelim(info, buff, &j))
				break;
			j++;
		} /*Update index for next read position*/
		idx = j + 1;
		if (idx >= k)/*If buffer is exhausted*/
		{ /*Reset indices and set command buffer type to normal*/
			idx = k = 0;
			info->cmd_buf_type = COMMAND_NORM;
		}
		*p = s;
		return (_strlen(s));
	}
	*p = buff;/*set arg ptr to buffer*/
	return (rd);/*ret read status*/
}
