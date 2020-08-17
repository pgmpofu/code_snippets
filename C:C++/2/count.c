#include <stdio.h>
#include <ctype.h>

int word( int c )
{
  if( c >= 'a' && c <= 'z' )
    return 1;

  if( c >= 'A' && c <= 'Z' )
    return 1;

  if( c == 39 )
    return 1;

  return 0;
}

int main()
{
    unsigned long int charcount = 0;
    unsigned long int linecount = 0;
    unsigned long int wordcount = 0;
    //char input = '\0';
    int input = 0;
    int inside_word =0;

    {
        while (1)
        {
            input = getchar();
            if (input == EOF)
            break;
      
            charcount ++;

            if (input == '\n')
            {
                linecount++;
            }

            if (inside_word & !word(input) )
            {
                wordcount++;
                inside_word = 0;
            }
            else if ((!inside_word) & word(input))
            {
                inside_word = 1;
            }
        }
        printf("%lu %lu %lu\n", charcount, wordcount, linecount);
        return 0;
    }
}
