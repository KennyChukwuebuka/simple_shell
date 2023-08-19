#include "main.h"
/**
 * custfork - Function fork command
 * @info: Params
 * Return: nothing
 */
void custfork(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, _custgetenviron(info)) == -1)
		{
			_freeinfostrcttype(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
				print_er(info, "Perm not granted\n");
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
		if (_isdelim(info->arg[i], " \t\n"))
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

