#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("false\n");
    }
    else if (strstr(argv[1], argv[2]))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}
