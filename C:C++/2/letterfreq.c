#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

float normalize(int count, int sum)
{
    return (float)count / (float)sum;
}

int main(int argc, char const *argv[])
{
    const int len = 50;
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int counts[len];
    char* input = malloc(sizeof(char) * len);

    for (int x = 0; x < len; x++) {
        counts[x] = 0;
    }

    while (scanf("%s", input) != EOF)
    {
        for (unsigned long i = 0; i < strlen(input); i++)
        {
            unsigned char c = input[i];
            if (isalpha(c))
            {
                counts[(tolower(c) - 'a')]++;
            }
        }
    }

    //Find the sum of all counts
    int sum = 0;
    for (unsigned long s = 0; s < sizeof(counts) / sizeof(int); s++)
    {
        sum += counts[s];
    }

    for (unsigned long j = 0; j < (sizeof(alphabet) / sizeof(char)) -1; j++)
    {
        if (counts[j] != 0) {
            printf("%c %.4f\n", alphabet[j], normalize(counts[j], sum));
        }

    }

    return 0;
}
