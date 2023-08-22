#include "main.h"
/**
 * cust_memset - Function that provide mem with byte
 * @t: params
 * @d: params
 * @m: params
 * Return: pointer
*/
char *cust_memset(char *t, char d, unsigned int m)
{
	unsigned int i;

	for (i = 0; i < m; i++)
		t[i] = d;
	return (t);
}
/**
 * full_free - Function free string fully
 * @sap: Params
 * Return: nothing
 */
void full_free(char **sap)
{
	char **i = sap;

	if (!sap)
		return;
	while (*sap)
		free(*sap++);
	free(i);
}
/**
 * _blockrealloc - Function that realloc mem
 * @ptr: Params
 * @o_bsize: Params
 * @n_bsize: Params
 * Return: ptr
 */
void *_blockrealloc(void *ptr, unsigned int o_bsize, unsigned int n_bsize)
{
	char *b;

	if (!ptr)
		return (malloc(n_bsize));
	if (!n_bsize)
		return (free(ptr), NULL);
	if (n_bsize == o_bsize)
		return (ptr);

	b = malloc(n_bsize);
	if (!b)
		return (NULL);
	o_bsize = o_bsize < n_bsize ? o_bsize : n_bsize;
	while (o_bsize--)
		b[o_bsize] = ((char *)ptr)[o_bsize];
	free(ptr);
	return (b);
}

