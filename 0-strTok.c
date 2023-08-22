#include "main.h"
/**
 * str_tokn - Function that split string
 * @str: Params
 * @t: Params
 * Return: pointer OR NULL
 */

char **str_tokn(char *str, char *t)
{
	int ar, ba, ca, da, co_word = 0;
	char **st;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!t)
		t = " ";
	for (ar = 0; str[ar] != '\0'; ar++)
		if (!_isdelim(str[ar], t) && (_isdelim(str[ar + 1], t) || !str[ar + 1]))
			co_word++;
	if (co_word == 0)
		return (NULL);
	st = malloc((1 + co_word) * sizeof(char *));
	if (!st)
		return (NULL);
	for (ar = 0, ba = 0; ba < co_word; ba++)
	{
		while (_isdelim(str[ar], t))
			ar++;
		ca = 0;
		while (!_isdelim(str[ar + ca], t) && str[ar + ca])
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
