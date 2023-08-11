#include "main.h"

/**
 * _strtok - String token function
 * @str: String params
 * @delim: delmeters
 *
 * Return: string
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastTok;

	if (str)
	{
		lastTok = str;
	} else
	{
		if (!lastTok)
		{
			return (NULL);
		}
		str = lastTok;
	}

	str += strspn(str, delim);

	if (*str == '\0')
	{
		lastTok = NULL;
		return (NULL);
	}

	char *tokenStart = str;

	str += strcspn(str, delim);

	if (*str)
	{
		*str++ = '\0';
		lastTok = str;
	} else
	{
		lastTok = NULL;
	}

	return (tokenStart);
}
