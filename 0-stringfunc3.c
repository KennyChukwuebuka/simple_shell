#include "main.h"

/**
 * str_chr - Function that get string characters
 * @str: Params
 * @c: Params
 * Return: NULL
 */
char *str_chr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
/**
 * str_n_cat - Function concat two string
 * @des: Params
 * @src: Params
 * @ent: Params
 * Return: str
 */
char *str_n_cat(char *des, char *src, int ent)
{
	int i = 0, j = 0;
	char *str = des;

	while (des[i] != '\0')
		i++;
	while (src[j] != '\0' && j < ent)
	{
		des[i] = src[j];
		i++;
		j++;
	}
	if (j < ent)
		des[i] = '\0';
	return (str);
}
/**
 * str_n_cpy - Function cpoies a string
 * @des: Params
 * @src: Params
 * @ent: Params
 * Return: String
 */
char *str_n_cpy(char *des, char *src, int ent)
{
	int i = 0, j;
	char *str = des;

	while  (src[i] != '\0' && i < ent - 1)
	{
		des[i] = src[i];
		i++;
	}
	if (i < ent)
	{
		j = i;
		while (j < ent)
		{
			des[j] = '\0';
			j++;
		}
	}
	return (str);
}





