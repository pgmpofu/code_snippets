/* 
 * intarr.h
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 * 
 */

/* DO NOT CHANGE THIS FILE - YOUR CODE WILL BE COMPILED AGAINST THE
   ORIGINAL. NON-COMPILING CODE WILL FAIL ALL THE TASKS!

   FOR TASKS WITH MORE THAN ONE FUNCTION, YOU MUST IMPLEMENT ALL
   FUNCTIONS TO PASS THE TASK.
*/
/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/
#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

int intarr_save_binary(intarr_t *ia, const char *filename)
{
    if (ia != NULL && filename != NULL)
    {
        FILE *file = fopen(filename, "wb");
        if (file != NULL)
        {
            fwrite(ia->data, sizeof(int), ia->len, file);
        }
        fclose(file);
        return 0;
    }
    return 1;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t *intarr_load_binary(const char *filename)
{
    if (filename != NULL)
    {
        FILE *file = fopen(filename, "rb");
        if (file != NULL)
        {
            fseek(file, 0, SEEK_END);
            long int len = ftell(file) / sizeof(int);
            rewind(file);
            intarr_t *result = intarr_create(len);
            fread(result->data, sizeof(int), len, file);
            fclose(file);
            return result;
        }
    }
    return NULL;
}