#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
char *buffer = NULL;
size_t buffer_size = 0;
ssize_t n_char;
char *token;
char **array;
int status, i = 0;
pid_t pid;
array = (char **)malloc(sizeof(char *) * 1024);
while (1)
{
write(1, "$ ", 2);
n_char = getline(&buffer, &buffer_size, stdin);
if (n_char == -1)
{
perror("getline");
break;
}
token = strtok(buffer, " \t\n");
i = 0;
while (token)
{
array[i] = token;
token = strtok(NULL, " \t\n");
i++;
}
array[i] = NULL;
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(array[0], array) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
else {
wait(&status);
}
}

free(buffer);
free(array);
return 0;
}
