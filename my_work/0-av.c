#include <stdio.h>

/**
 * _av - Entry point
 * @ac: number of items
 * @av: NULL terminated arr of str
 *
 * Return: arguments
 */

int _av(int ac, char **av)
{	int i;
	(void)ac;
	i = 1;
	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}

