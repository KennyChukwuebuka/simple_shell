#include "main.h"

/**
 * _exec - execve example
 *
 * Return: Always 0.
 */
int _exec(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	char *envp[] = {NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
