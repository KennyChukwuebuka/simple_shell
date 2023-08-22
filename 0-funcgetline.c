#include "main.h"
/**
 * _custreadbuff - Function that read buffer
 * @info: Params
 * @buf: Params
 * @idn: Params
 * Return: nothing
 */
ssize_t _custreadbuff(info_t *info, char *buf, size_t *idn)
{
	ssize_t red = 0;

	if (*idn)
		return (0);
	red = read(info->readfd, buf, READ_BUF_SIZE);
	if (red >= 0)
		*idn = red;
	return (red);
}
/**
 * cust_getline - Function that gets line from Standard inp
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

	sp = *ptrs;
	if (sp && len)
		st = *len;
	if (i == j)
		i = j = 0;
	rd = _custreadbuff(info, buf, &j);
	if (rd == -1 || (rd == 0 && j == 0))
		return (-1);
	c = str_chr(buf + i, '\n');
	s = c ? 1 + (unsigned int)(c - buf) : j;
	n_sp = _blockrealloc(sp, st, st ? st + s : s + 1);

	if (!n_sp)
		return (sp ? free(sp), -1 : -1);
	if (st)
		str_n_cat(n_sp, buf + i, s - i);
	else
		str_n_cpy(n_sp, buf + i, s - i + 1);
	st += s - i;
	i = s;
	sp = n_sp;
	if (len)
		*len = st;
	*ptrs = sp;
	return (st);
}
/**
 * _custgetinput - Function get input
 * @info: Params
 * Return: byte
 */
ssize_t _custgetinput(info_t *info)
{
	static char *buff;
	static size_t idx, j, k;
	ssize_t rd = 0;
	char **p = &(info->arg), *s;

	_putchar(BUF_FLUSH);
	rd = custinp_buf(info, &buff, &k);
	if (rd == -1)
		return (-1);
	if (k)
	{
		j = idx;
		s = buff + idx;
		checkcont_chain(info, buff, &j, idx, k);
		while (j < k)
		{
			if (_ischaindelim(info, buff, &j))
				break;
			j++;
		}
		idx = j + 1;
		if (idx >= k)
		{
			idx = k = 0;
			info->cmd_buf_type = COMMAND_NORM;
		}
		*p = s;
		return (_strlen(s));
	}
	*p = buff;
	return (rd);
}
