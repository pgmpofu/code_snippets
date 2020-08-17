#include <stdio.h>
#include <stdlib.h>
#include "point_array.h"

void point_array_init(point_array_t *pa)
{
    //Do not try to initialize null array
    if (pa)
    {
        pa->len = 0;
        pa->reserved = 0;
        pa->points = NULL;
    }
}

void point_array_reset(point_array_t *pa)
{
    //Do not try to reset null array
    if (pa)
    {
        pa->len = 0;
        pa->reserved = 0;
        free(pa->points);
        free(pa);
    }
}

int point_array_append(point_array_t *pa, point_t *p)
{
    //Increase length, allocate new space and add element
    if (pa)
    {
        pa->len++;
        pa->points = realloc(pa->points, (2 * pa->len * sizeof(point_t)));
        pa->points[pa->len - 1] = *p;
        pa->reserved = sizeof(pa->points);
        return 0;
    }
    return 1;
}

int point_array_remove(point_array_t *pa, unsigned int i)
{
    
    if (pa)
    {
        if (i >= pa->len && i >= 0)
        {
            return 1;
        }
        else
        {
            //Overwrite element at i with last element in the array
            // Reduce length of array
            //Realloc with new space requirements
            pa->points[i] = pa->points[pa->len - 1];
            pa->len--;
            pa->points = realloc(pa->points, pa->len * sizeof(point_t));
            pa->reserved = sizeof(pa->points);
            return 0;
        }
    }
    return 1;
}
