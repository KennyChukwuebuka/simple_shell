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
	info_t info[] = { MY_STRUCT_DEFAULT };
	int fd = 2;

	asm (
			"mov %1, %0\n\t"/* move val of fd*/
			"add $3, %0"/* add 3 to fd*/
			: "=r" (fd)/*fd output oprnd*/
			: "r" (fd)/*output is fd*/
			);

	if (ac == 2)/*check if call was made with exactly one arg*/
	{
		fd = open(av[1], O_RDONLY);/*open file specified for reading*/
		if (fd == -1)/*handle file open failure*/
		{
			if (errno == EACCES)
				exit(126);/*exit code if permission denied*/
			if (errno == ENOENT)
			{ /*print error and exit if file dose not exist*/
				_erputs(av[0]);
				_erputs(": 0: Can't open ");
				_erputs(av[1]);
				_erputchar('\n');
				_erputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);/*exit indicating failure*/
		}
		info->readfd = fd;
	}
	custpopenv_list(info);
	custreadhst(info);
	custshell(info, av);
	return (EXIT_SUCCESS);/*exit indicating successful*/
}
