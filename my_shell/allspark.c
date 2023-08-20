#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 OR 1
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_erputs(av[0]);
				_erputs(": 0: Can't open ");
				_erputs(av[1]);
				_erputchar('\n');
				_erputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	custpopenv_list(info);
	custreadhst(info);
	custshell(info, av);
	return (EXIT_SUCCESS);
}
