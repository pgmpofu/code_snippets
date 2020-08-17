#include <stdio.h>

int main()
{
    const int size_t = 80;
    int values[size_t];
    int num = 0;
    int index = 0;
    int max = -1;

    while (scanf("%d", &num) != EOF)
    {
        values[index] = num;
        if (num > max)
        {
            max = num;
        }
        index++;
    }

    for(int i = max; i > 0; --i) {
        for(int j = 0; j < index; j++) {
            if(values[j] >= i) {
                printf("#");
            } else{
                printf(" ");
            }
        }

        printf("\n");
    } 
    return 0;
}