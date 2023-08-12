#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[])
{
extern char **environ;
printf("Address of env (third parameter): %p\n", (void *)env);
printf("Address of environ (global variable): %p\n", (void *)environ);
if (env == environ)
{
printf("env and environ have the same address.\n");
}
else
{
printf("env and environ have different addresses.\n");
}
return (0);
}
