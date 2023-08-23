#include "main.h"

/**
 * _custgetenviron - Function responsible for retrieving environment
 * variable stored within the custom data structure
 * @info: Params
 * Return: 0
 */
char **_custgetenviron(info_t *info)
{ /*check if the environment variable has not bin fetch or if it has*/
	if (!info->environ || info->env_changed)
	{ /*convert llist of environment variable to str array*/
		info->environ = customlist_tostring(info->env);
		info->env_changed = 0;/*reset the environment env_ch flag*/
	}
	return (info->environ);/*ret ptr to arr of environment variable str*/
}
/**
 * custpopenv_list - Function that populates the linked list of
 * environemt variable within the ifo structure using environ
 * @info: Params
 * Return: 0
 */
int custpopenv_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;
/*iterate through the environment variable arr*/
	for (i = 0; environ[i]; i++)
		addnodeto_end(&node, environ[i], 0);
	info->env = node;/*assign the llist of environment var to info strct*/
	return (0);/*0 indicate a success*/
}
/**
 * isfile_cmd - Function to determine if file path points to
 * a regular file
 * @info: Params
 * @p: Params
 * Return: 1 OR 0
 */
int isfile_cmd(info_t *info, char *p)
{
	struct stat fst;

	(void)info;/*suppress unsed variable*/
	if (!p || stat(p, &fst))/*chck if p NULL OR stat func fails for p*/
		return (0);/*ret 0 indicate p is not a valid file*/
	if (fst.st_mode & S_IFREG)/*chck if st_mode of stat strct indcate a reg file*/
	{
		return (1);/*1 idicate p is a reg file*/
	}
	return (0);/*if no condition is met ret 0, p is not regular file*/
}
/**
 * characdup - Function that creaes new char string by copying
 * charater from input str within a specified range
 * @pstr: Params
 * @st: Params
 * @end: Params
 * Return: ptr
 */
char *characdup(char *pstr, int st, int end)
{
	static char buf[1024];
	int i = 0, j = 0;
/*Loop through the character in the range*/
	for (j = 0, i = st; i < end; i++)
		if (pstr[i] != ':')
			buf[j++] = pstr[i];
	buf[j] = 0;/*NULL - Terminate the resulting string*/
	return (buf);/*return the pointer of resulting string*/
}
/**
 * custfindpath - Function that finds path of str
 * @info: Params
 * @pstr: Params
 * @c: Params
 * Return: path
 */
char *custfindpath(info_t *info, char *pstr, char *c)
{
	int i = 0, c_pos = 0;
	char *p;

	if (!pstr)/*check if pstr is NULL*/
		return (NULL);/*return NULL if pstr is null*/
	if ((_strlen(c) > 2) && _startwith(c, "./"))/*chck if c st with ./ n is file*/
	{
		if (isfile_cmd(info, c))
			return (c);/*return c if is a valid file*/
	}
	while (1)/*loop through*/
	{
		if (!pstr[i] || pstr[i] == ':')/*chck end of path str or delim ':'*/
		{
			p = characdup(pstr, c_pos, i);/*create a path combine pstr n c*/
			if (!*p)
				_strcat(p, c);/*concat c to path if pstr path is empty*/
			else
			{
				_strcat(p, "/");/*concat '/' to path*/
				_strcat(p, c);/*concat c to path*/
			}
			if (isfile_cmd(info, p))/*check if path is valid*/
				return (p);/*return valid path*/
			if (!pstr[i])/*break loop if end of path str is reached*/
				break;
			c_pos = i;/*update c_pos to current position*/
		}
		i++;/*move to next character*/
	}
	return (NULL);/*return NULL if a valid path is not found*/
}

