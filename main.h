#ifndef MAIN_H
#define MAIN_H

/* librairies*/
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>

/*====read and write buff====*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*=========Command===========*/

#define COMMAND_NORM	0
#define COMMAND_OR	1
#define COMMAND_AND	2
#define COMMAND_CHAIN	3

/*====Converter func=====*/
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/*======func getline=======*/
#define USE_GETLINE 0
#define USE_STRTOK 0

/*========event func=========*/
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/*======list struct=====*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/*====Struct_001====*/
typedef struct
{
	char *arg;
	int readfd;
	int argc;
	unsigned int line_count;
	int linecount_flag;
	char *fname;
	char **argv;
	list_t *env;
	int env_changed;
	char **environ;
	int status;
	int er_num;
	list_t *history;
	list_t *alias;
	char *path;
	char **cmd_buf;
	int cmd_buf_type;
	int histcount;
} info_t;

/*This macro defines an initializer my structure of the type info_t above*/
/*it initializes each member of the structure with specific values*/
/*the structure member are in the same order as declared above*/
#define MY_STRUCT_DEFAULT \
{ \
	0, /*char arg*/ \
	0, /*int readfd*/ \
	0, /*unsigned int line_count*/ \
	0, /*int linecount_flag*/ \
	0, /*char *fname*/ \
	0, /*char **argv*/ \
	0, /*list_t *env*/ \
	NULL, /*int env_changed*/ \
	0, /*char **environ*/ \
	NULL, /*int status*/ \
	0, /*int status*/ \
	0, /*int er_num*/ \
	0, /*list_t *history*/ \
	0, /*list_t *alias*/ \
	NULL, /*char *path*/ \
	0, /*char **cmd_buf*/ \
	0, /*int cmd_buf_type*/ \
	0  /*int histcount*/ \
	}


/*=====megatron======*/
typedef struct megain
{
	char *type;
	int (*func)(info_t *);
} mega_table;

/* User input */
#define MAX_USER_INPUT_COMMAND 100

/*======== Proptotypes============== */
int _printstr(char *s);
int _putchar(char c);
char *_strtok(char *str, const char *delim);

/*====optimus====*/
int _isdelim(char c, char *delim);
int intsatty(info_t *i);
int _isalpha(int c);
int _atoi(char *s);

/*====megatron========*/
int megatron(info_t *info);

/*====error file====*/
int _putcfd(char c, int fd);
int _putstrfd(char *str, int fd);
void _erputs(char *str);
int _erputchar(char c);
int cust_als(info_t *info);

/*====error file 2=========*/
void rp_com(char *buf);
int _ersatoi(char *s);
int _printd(int input, int fd);
void print_er(info_t *i, char *estr);
char *conv_num(long int num, int base, int flg);

/*====string func1=====*/
int _strcmp(char *str1, char *str2);
int _strlen(char *s);
char *_startwith(const char *hay, const char *ned);
char *_strcat(char *des, char *src);

/*====string / char func2===*/
char *str_dup(const char *str);
char *str_cpy(char *des, char *src);
void _puts(char *s);
int _putchar(char c);

/*=====string exit func3====*/
char *str_n_cpy(char *des, char *src, int ent);
char *str_n_cat(char *des, char *src, int ent);
char *str_chr(char *str, char c);

/*=====str tokniza========*/
char **str_tokn(char *str, char *t);
char **str_tokna(char *str, char t);

/*====func list========*/
size_t prt_liststr(const list_t *);
list_t *addnodeto_end(list_t **head, const char *str, int num);
int del_node_i(list_t **head, unsigned int ind);

/*=====func list1========*/
list_t *_myaddnode(list_t **head, const char *str, int num);
void list_free(list_t **ptr_tohead);
void checkcont_chain(info_t *info, char *buff, size_t *s, size_t j, size_t len);
int _ischaindelim(info_t *info, char *buff, size_t *s);

/*======func list2=======*/
ssize_t custgetnode_ind(list_t *head, list_t *node);
size_t _mylist_print(const list_t *j);
size_t _tolistlen(const list_t *j);

/*=======func list3=============*/
char **customlist_tostring(list_t *head);
list_t *custnodestart_with(list_t *node, char *start, char c);
int custfrees(void **ptr);
void _freeinfostrcttype(info_t *info, int a);
void init_info(info_t *info, char **s);

/*======func environment====*/
char *_custgetenv(info_t *info, const char *name);
int _custenv(info_t *info);
int cust_unset_env(info_t *info, char *va);

/*====func environment 1======*/
int _cust_setenv(info_t *info, char *ar, char *val);
int cust_setenv(info_t *info);
int cust_un_setenv(info_t *info);

/*=======func environment 2===========*/
int custpopenv_list(info_t *info);
char **_custgetenviron(info_t *info);
int isfile_cmd(info_t *info, char *p);
char *characdup(char *pstr, int st, int end);
char *custfindpath(info_t *info, char *pstr, char *c);

/*======mem allocation======*/
char *cust_memset(char *t, char d, unsigned int m);
void *_blockrealloc(void *ptr, unsigned int o_bsize, unsigned int n_bsize);
void full_free(char **sap);

/*========func action===============*/
int cust_extshell(info_t *info);
int cust_helpcd(info_t *info);
int custunsetals(info_t *info, char *str);

/*=====func init==============*/
int cust_chdir(info_t *info);
int custhistory_list(info_t *info);
int custsetals(info_t *info, char *str);

/*==========func actinit==============*/
int custprtals(list_t *node);
void st_info_clear(info_t *info);
int _repstr(char **o_str, char *n_str);
int custrepvars(info_t *info);
int custrepals(info_t *info);

/*=======event func============*/
char *cust_histfile(info_t *info);
int cust_wrthist(info_t *info);

/*=======event func1===========*/
int custre_numhst(info_t *info);
int custbhist(info_t *info, char *buff, int c);
int custreadhst(info_t *info);

/*=========func getline==========*/
ssize_t _custreadbuff(info_t *info, char *buf, size_t *idn);
int cust_getline(info_t *info, char **ptrs, size_t *len);
ssize_t _custgetinput(info_t *info);

/*======signal func===========*/
void custsignal(__attribute__((unused))int sig);
ssize_t custinp_buf(info_t *info, char **buff, size_t *c);

/**==========func command======*/
void custfork(info_t *info);
void _custfindpathcmd(info_t *info);
int custshell(info_t *, char **);
#endif /*main.h*/
