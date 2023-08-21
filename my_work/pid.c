#include "main.h"

/**
 * _mypid - PID
 *
 * Return: Always 0.
 */
int _mypid(void)
{
	pid_t my_pid, my_ppid;

	my_ppid = getppid();
	my_pid = getpid();

	printf("This is my_pid %u\n", my_pid);
	printf("This is my_ppid %u\n", my_ppid);

	return (0);
}
