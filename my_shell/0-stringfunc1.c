#include "main.h"

/**
 * _startwith - Function that check if
 * one str starts with another
 * @hay: Params
 * @ned: Params
 * Return: NULL OR Address
 */
char *_startwith(const char *hay, const char *ned)
{
	while (*ned)
		if (*ned++ != *hay++)
			return (NULL);
	return ((char *)hay);
}
/**
 * _strcat - Function that concat string
 * @des: Params
 * @src: Params
 * Return: str
 */
char *_strcat(char *des, char *src)
{
	char *res = des;

	while (*des)
		des++;
	while (*src)
		*des++ = *src++;
	*des = *src;
	return (res);
}
/**
 * _strlen - Function that return lenght of string
 * @s: Params
 * Return: string len
 */
int _strlen(char *s)
{
	int init = 0;

	if (!s)
		return (0);

	while (*s++)
		init++;
	return (init);
}
/**
 * _strcmp - Function that compare string
 * @str1: Params
 * @str2: Params
 * Return: str
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

