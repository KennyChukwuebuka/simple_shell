#include <stdio.h>

int main(int ac, char **av) {
         (void)ac;
    int i = 1; // Start from av[1] to skip the program name in av[0]

    while (av[i] != NULL) {
        printf("%s\n", av[i]);
        i++;
    }

    return 0;
}

