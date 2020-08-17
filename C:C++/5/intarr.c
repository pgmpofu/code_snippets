/* 
 * @author Patience Mpofu
 * @date 05 July 2020
 * intarr.c
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 * 
 */

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"
intarr_t *intarr_create(unsigned int len)
{
    intarr_t *new_struct = malloc(len * sizeof(intarr_t));
    new_struct->data = malloc(len * sizeof(intarr_t));
    new_struct->len = len;
    {
        if (new_struct != NULL)
        {
            return new_struct;
        }
    }
    return NULL;
}

// Frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy(intarr_t *ia)
{
    if (ia != NULL)
    {
        free(ia);
        ia = NULL;
    }
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set(intarr_t *ia,
                           unsigned int index,
                           int val)
{
    if (ia != NULL && index < ia->len)
    {
        ia->data[index] = val;
        return INTARR_OK;
    }
    else if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    return INTARR_BADINDEX;
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get(const intarr_t *ia,
                           unsigned int index,
                           int *val)
{
    if (ia != NULL && index < ia->len && val != NULL)
    {
        *val = ia->data[index];
        return INTARR_OK;
    }
    else if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    return INTARR_BADINDEX;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t *intarr_copy(const intarr_t *ia)
{
    intarr_t *ptr = malloc(sizeof(ia));
    ptr->data = malloc(ia->len * sizeof(int));
    ptr->len = sizeof(ia->len);
    if (ptr != NULL)
    {
        ptr->len = ia->len;
        for (int i = 0; i < ia->len; i++)
        {
            ptr->data[i] = ia->data[i];
        }
        return ptr;
    }
    return NULL;
}

/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_sort(intarr_t *ia)
{
    if (ia != NULL)
    {
        for (int i = 0; i < ia->len; i++)
        {
            for (int j = i + 1; j < ia->len; j++)
            {
                if (ia->data[i] > ia->data[j])
                {
                    ia->data[i] ^= ia->data[j];
                    ia->data[j] ^= ia->data[i];
                    ia->data[i] ^= ia->data[j];
                }
            }
        }

        return INTARR_OK;
    }
    return INTARR_BADARRAY;
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find(intarr_t *ia, int target, int *i)
{
    if (ia != NULL && i != NULL)
    {
        for (int j = 0; j < ia->len; j++)
        {
            if (ia->data[j] == target)
            {
                *i = j;
                return INTARR_OK;
            }
        }
    }
    else if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push(intarr_t *ia, int val)
{
    if (ia != NULL)
    {
        ia->len += 1;
        ia->data = realloc(ia->data, ia->len * sizeof(int));
        ia->data[ia->len - 1] = val;
        return INTARR_OK;
    }
    else if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    return INTARR_BADALLOC;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop(intarr_t *ia, int *i)
{
    if (ia != NULL && i != NULL)
    {
        if (ia->len > 0)
        {
            *i = ia->data[ia->len - 1];
            ia->len -= 1;
            ia->data = realloc(ia->data, sizeof(int) * ia->len);
            return INTARR_OK;
        }
    }
    else if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    return INTARR_BADINDEX;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded.
// If newlen is greater than the original array length, the values
// of the new integers will be undefined
// (see https://en.cppreference.com/w/c/memory/realloc).
// If the allocation is successful, return INTARR_OK, otherwise
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize(intarr_t *ia, unsigned int newlen)
{
    if (ia != NULL)
    {
        ia->data = realloc(ia->data, newlen * sizeof(int));
        ia->len = newlen;
        return INTARR_OK;
    }
    else if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds,
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t *intarr_copy_subarray(intarr_t *ia,
                               unsigned int first,
                               unsigned int last)
{
    if (first >= 0 && first <= last && ia != NULL && last <= ia->len)
    {
        intarr_t *sub_arr = malloc(sizeof(intarr_t));
        sub_arr->len = (last - first) + 1;
        sub_arr->data = malloc(sub_arr->len * sizeof(int));
        int index = 0;
        if (sub_arr != NULL && ia->data != NULL)
        {
            for (int i = first; i <= last; i++, index++)
            {
                sub_arr->data[index] = ia->data[i];
            }
        }
        return sub_arr;
    }
    return NULL;
}