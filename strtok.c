#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **splitter(char *str)
{
        char *token, **tokens = NULL;
        int i = 0;

        token = strtok(str, " \t\n");
        while (token != NULL)
        {
                i++;
                tokens = realloc(tokens, i * sizeof(char *));
                if (tokens == NULL)
                {
                        perror("realloc");
                        exit(EXIT_FAILURE);
                }
                tokens[i - 1] = token;
                token = strtok(NULL, " \t\n");
        }

        for (i = 0; tokens[i]; i++)
                printf("%s\n", tokens[i]);

        return (tokens);
}

int main(void)
{
        char *buffer = NULL, **tokens = NULL;
        size_t size_buffer = 0;
        ssize_t n_char = 0;
        int i = 0;

        printf("$ ");
        n_char = getline(&buffer, &size_buffer, stdin);
        if (n_char == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        buffer[n_char - 1] = '\0';

        tokens = splitter(buffer);

        for (i = 0; tokens[i] != NULL; i++)
        {
                printf("%s\n", tokens[i]);
                free(tokens[i]);
        }
        free(tokens);
        free(buffer);

        return 0;
}

