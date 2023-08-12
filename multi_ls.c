#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
int i = 0;
pid_t pid;
int status;
char *args[] = {"/bin/ls", "-a", "/tmp", NULL};
for (i = 0; i < 5; i++)
{
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
}
else
wait(&status);
}
exit(EXIT_SUCCESS);
