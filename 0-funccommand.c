#include "main.h"
/**
 * custfork - Function fork command
 * @info: Params
 * Return: nothing
 */
void custfork(info_t *info)
{
	pid_t child_pid;/*variable to store child process*/
/*fork the current process to create new child process*/
	child_pid = fork();
	if (child_pid == -1)/*check if forking was unsuccessful*/
	{
		perror("Error:");/*print errr*/
		return;/*exit function*/
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, _custgetenviron(info)) == -1)
		{
			_freeinfostrcttype(info, 1);
			if (errno == EACCES)/*handle execve error*/
				exit(126);/*permission denied exit code*/
			exit(1);/*exit with 1 if other error*/
		}
	}
	else
	{
		wait(&(info->status));/*wait for child process to finish*/
		if (WIFEXITED(info->status))/*check if child process exited normal*/
		{
			info->status = WEXITSTATUS(info->status);/*get exit status*/

			if (info->status == 126)/*if exit status 126*/
				print_er(info, "Perm not granted\n");/*print error msg*/
		}
	}
}
/**
 * _custfindpathcmd - Function that find path
 * @info: Params
 * Return: nothing
 */
void _custfindpathcmd(info_t *info)
{
	int i, j;
	char *p = NULL;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, j = 0; info->arg[i]; i++)
		if (!_isdelim(info->arg[i], " \t\n"))
			j++;
	if (!j)
		return;
	p = custfindpath(info, _custgetenv(info, "PATH="), info->argv[0]);
	if (p)
	{
		info->path = p;
		custfork(info);
	}
	else
	{
		if ((intsatty(info) || _custgetenv(info, "PATH=") || info->argv[0][0] == '/')
				&& isfile_cmd(info, info->argv[0]))
			custfork(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_er(info, "not found\n");
		}
	}
}
/**
 * custshell - Function shell
 * @info: Params
 * @s: Params
 * Return: 0 OR 1
 */
int custshell(info_t *info, char **s)
{
	ssize_t q = 0;
	int ret = 0;

	while (q != -1 && ret != -2)
	{
		st_info_clear(info);
		if (intsatty(info))
			_puts("$ ");
		_erputchar(BUF_FLUSH);
		q = _custgetinput(info);
		if (q != -1)
		{
			init_info(info, s);
			ret = megatron(info);
			if (ret == -1)
				_custfindpathcmd(info);
		}
		else if (intsatty(info))
			_putchar('\n');
		_freeinfostrcttype(info, 0);
	}
	cust_wrthist(info);
	_freeinfostrcttype(info, 1);
	if (!intsatty(info) && info->status)
		exit(info->status);
	if (ret == -2)
	{
		if (info->er_num == -1)
			exit(info->status);
		exit(info->er_num);
	}
	return (ret);
}

