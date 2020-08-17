/* LAB 6 TASK 2 */
#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

const char openBrace = '[';
const char closeBrace = ']';
const char comma = ',';

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json(intarr_t *ia, const char *filename)
{
    if (ia != NULL && filename != NULL)
    {
        FILE *file = fopen(filename, "wb");
        {
            if (file != NULL && ia->data != NULL && ia->len > 0)
            {
                fputc(openBrace, file);
                fprintf(file, "%s", "\n");
                for (int i = 0; i < ia->len; i++)
                {
                    if (i != ia->len - 1)
                    {
                        fprintf(file, "%d%c\n", ia->data[i], comma);
                    }
                    else
                    {
                        fprintf(file, "%d\n", ia->data[i]);
                    }
                }
                fputc(closeBrace, file);
                fclose(file);
                return 0;
            }
            else if (ia->len == 0)
            {
                fputc(openBrace, file);
                fputc(closeBrace, file);
                fclose(file);
                return 0;
            }
        }
    }
    return 1;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t *intarr_load_json(const char *filename)
{
    if (filename != NULL)
    {
        FILE *file = fopen(filename, "rb");
        if (file != NULL)
        {
            int output;
            unsigned int count = 0;

            while (fscanf(file, "%*s%*c%d", &output) != EOF)
            {
                count++;
            }

            printf("%d", count);

            fclose(file);

            intarr_t *input = intarr_create(count);
            FILE *reopened = fopen(filename, "rb");
            if (reopened != NULL)
            {
                for (int i = 0; i < count; i++)
                {
                    fscanf(reopened, "%*s%*c%d", &input->data[i]);
                }
            }
            fclose(reopened);
            return input;
        }
    }
    return NULL;
}