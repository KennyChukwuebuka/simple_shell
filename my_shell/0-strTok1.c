#include "main.h"
/**
 * str_tokna - Functon tha split string to word
 * @str: Param
 * @t: Param
 * Return: pointer OR NULL
 */

char **str_tokna(char *str, char t)
{
	int ar, ba, ca, da, co_word = 0;
	char **st;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (ar = 0; str[ar] != '\0'; ar++)
		if ((str[ar] != t && str[ar + 1] == t) ||
		(str[ar] != t && !str[ar + 1]) || str[ar + 1] == t)
			co_word++;
	if (co_word == 0)
		return (NULL);
	st = malloc((1 + co_word) * sizeof(char *));
	if (!st)
		return (NULL);
	for (ar = 0, ba = 0; ba < co_word; ba++)
	{
		while (str[ar] == t && str[ar] != t)
			ar++;
		ca = 0;
		while (str[ar + ca] != t && str[ar + ca] && str[ar + ca] != t)
			ca++;
		st[ba] = malloc((ca + 1) * sizeof(char));
		if (!st[ba])
		{
			for (ca = 0; ca < ba; ca++)
				free(st[ca]);
			free(st);
			return (NULL);
		}
		for (da = 0; da < ca; da++)
			st[ba][da] = str[ar++];
		st[ba][da] = 0;
	}
	st[ba] = NULL;
	return (st);
}

