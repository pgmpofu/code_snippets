#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    unsigned long len = 1000;
    char *input = malloc(sizeof(char) * len);
    char *stored = malloc(sizeof(char) * len);
    char *query_strings = malloc(sizeof(char) * len);
    char censored[] = "CENSORED ";

    for (int k = 1; k < argc; k++)
    {
        strcat(query_strings, " ");
        strcat(query_strings, argv[k]);
    }

    while (scanf("%s", input) != EOF)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strncmp(argv[i], input, strlen(input) - 1) == 0 && strlen(argv[i]) <= strlen(input))
            {
                //Only add space if there is already something stored in the char array
                if (strlen(stored) > 0)
                {
                    strcat(stored, " ");
                }
                strncat(stored, censored, strlen(censored));
            }
            else if (strncmp(argv[i], input, strlen(input) - 1) != 0 && (strstr(query_strings, input) == NULL) && strstr(stored, input) == NULL)
            {
                if (strlen(stored) > 0)
                {
                    strcat(stored, " ");
                }
                strcat(stored, input);
            }
        }
    }
    puts(stored);
    return 0;
}
