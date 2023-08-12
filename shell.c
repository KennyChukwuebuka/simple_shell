#include "main.h"

/**
 * process_line - Process command function
 * @process: Params
 * @envp: Param
 *
 * Return: Process
 */
void process_line(char *process, char *envp[])
{
	pid_t child_pid = fork();
	int pro_status;
	char *argv[] = {process, NULL};

	if (child_pid == 0)
	{
		execve(process, argv, envp);
		perror("EXECVE Failed Process");
		exit(1);
	}
	else if (child_pid > 0)
	{
		waitpid(child_pid, &pro_status, 0);
	}
	else
	{
		perror("FORK Fail Process");
	}
}
/**
 * main - entry
 * @argc: arg count
 * @argv: arg vec
 * @envp: env var
 * Return: command line
 */
int main(int argc, char *argv[], char *envp[])
{
	char input[MAX_USER_INPUT_COMMAND];

	while (1)
	{
		printf("#cisfun$ ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		process_line(input, envp);
	}
	return (0);
}
