#include <stdio.h>
#include <stdlib.h>
#include "point_array.h"

void point_array_init(point_array_t *pa)
{
    //Do not try to initialize a null array
    if (pa)
    {
        pa->len = 0;
        pa->points = NULL;
    }
}

void point_array_reset(point_array_t *pa)
{
    //Do not try to reset a null array
    if (pa)
    {
        pa->len = 0;
        pa->points = NULL;
        free(pa->points);
        free(pa);
        pa = NULL;
    }
}

int point_array_append(point_array_t *pa, point_t *p)
{
    //Increment space length then allocate memory with the new length
    if (pa)
    {
        pa->len++;
        pa->points = realloc(pa->points, pa->len * sizeof(point_t));
        pa->points[pa->len - 1] = *p;
        return 0;
    }
    return 1;
}

int point_array_remove(point_array_t *pa, unsigned int i)
{
    //Overwrite last array element then decrement space
    if (pa->points)
    {
        if (i >= pa->len && i > 0)
        {
            return 1;
        }
        else
        {
            pa->points[i] = pa->points[pa->len-1];
            pa->len--;
            pa->points = realloc(pa->points, pa->len * sizeof(point_t));
            return 0;
        }
    }
     return 1;
}
