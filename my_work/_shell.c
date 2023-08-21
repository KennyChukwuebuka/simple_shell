#include "main.h"
#define MAX_ARGS 1024

/**
 * parseInput - Function Input
 * @input: Param
 * @args: Params
 * Return: nothing
 */

void parseInput(char *input, char **args)
{
	char *token = strtok(input, " \t\n");
	int i = 0;

	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}

	args[i] = NULL;
}
/**
 * executeCommand - Function execute
 * @args: Params
 * Return: nothing
 */
void executeCommand(char **args)
{
	pid_t pid;
	int status;
	char *envp[] = {NULL};
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_char;
	char *args[MAX_ARGS];

	while (1)
	{
		write(1, "$ ", 2);
		n_char = getline(&buffer, &buffer_size, stdin);

		if (n_char == -1)
		{
			/*perror("getline");*/
			break;
		}

		parseInput(buffer, args);
		executeCommand(args);
	}

	free(buffer);
	return (0);
}

