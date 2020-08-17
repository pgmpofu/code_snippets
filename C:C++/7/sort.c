#include <stdio.h>
#include "list.h"

//sort a list by swapping values
void list_sort(list_t *list)
{
    //immediately back out if there is nothing on the list
    if (list == NULL || list->head == NULL)
    {
        return;
    }

    //Count number of elements in the list
    element_t *count_ptr = list->head;
    int count = 0;

    while (count_ptr)
    {
        count++;
        count_ptr = count_ptr->next;
    }

    //Move everything into array
    element_t *current = list->head;
    int arr[count];
    int index = 0;

    while (current)
    {
        arr[index] = current->val;
        current = current->next;
        index++;
    }

    //Sort array
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }

    //Create new linked list
    element_t *sorted = list->head;
    int next_index = 0;
    while (sorted)
    {
        sorted->val = arr[next_index];
        next_index++;
        sorted = sorted->next;
    }
}