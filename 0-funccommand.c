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
 * _custfindpathcmd - Function that find path, fork child process
 * and execute command
 * @info: Params
 * Return: nothing
 */
void _custfindpathcmd(info_t *info)
{
	int i, j;
	char *p = NULL;
/*set the path of the command to the first argument*/
	info->path = info->argv[0];
	if (info->linecount_flag == 1)/*if linecount_flag is set update linecount*/
	{
		info->line_count++;
		info->linecount_flag = 0;
	} /*count non-delimeter arguments*/
	for (i = 0, j = 0; info->arg[i]; i++)
		if (!_isdelim(info->arg[i], " \t\n"))
			j++;
	if (!j)/*if no delimeter argument return */
		return;
		/*find command in the system PATH using cust function*/
	p = custfindpath(info, _custgetenv(info, "PATH="), info->argv[0]);
	if (p)
	{ /*If command found in PATH, update path and fork a child process*/
		info->path = p;
		custfork(info);
	}
	else
	{ /*If command not found in PATH, perform additional checks*/
		if ((intsatty(info) || _custgetenv(info, "PATH=") || info->argv[0][0] == '/')
				&& isfile_cmd(info, info->argv[0]))
			custfork(info);
		else if (*(info->arg) != '\n')/*If comd can be exec, fork a child prss*/
		{
			info->status = 127;/*if command not found and not a newline*/
			print_er(info, "not found\n");
		}
	}
}
/**
 * custshell - Function shell, the main custom shell
 * @info: Params
 * @s: Params
 * Return: 0 OR 1
 */
int custshell(info_t *info, char **s)
{
	ssize_t q = 0;
	int ret = 0;
/*Continuously execute shell commands until q is -1 or ret is -2*/
	while (q != -1 && ret != -2)
	{
		st_info_clear(info);/*Clear some information in the info structure*/
		if (intsatty(info))/*Check if the shell is interactive*/
			_puts("$ ");/*Print a prompt character*/
		_erputchar(BUF_FLUSH);/*Flush any buffered output*/
		q = _custgetinput(info);/*Get input from the user*/
		if (q != -1)/*If input is received*/
		{
			init_info(info, s);/*Initialize info structure with input data*/
			ret = megatron(info);/*Execute the "megatron" function*/
			if (ret == -1)/*If megatron returns -1*/
				_custfindpathcmd(info);/*find and execute the command*/
		}
		else if (intsatty(info))/*If no input and in interactive mode*/
			_putchar('\n');/*print newline*/
		_freeinfostrcttype(info, 0);/*Free resources in the info structure*/
	}
	cust_wrthist(info);/*Write shell history to a file*/
	_freeinfostrcttype(info, 1);/*Free resources in the info structure*/
	/*If not interactive and status is non-zero, exit with status*/
	if (!intsatty(info) && info->status)
		exit(info->status);
	if (ret == -2)/* Handle ret value of -2*/
	{
		if (info->er_num == -1)/*If error number is -1*/
			exit(info->status);/*Exit with status*/
		exit(info->er_num);/*otherwise exit using error number*/
	}
	return (ret);/*return value*/
}

