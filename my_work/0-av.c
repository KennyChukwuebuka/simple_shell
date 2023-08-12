#include <stdio.h>

/**
 * main - Entry point
 * @ac: number of items
 * @av: NULL terminated arr of str
 *
 * Return: arguments
 */

int main(int ac, char **av)
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

