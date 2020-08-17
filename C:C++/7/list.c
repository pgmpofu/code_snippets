#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_create()
{
    list_t *list = malloc(sizeof(list_t));
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

void list_destroy(list_t *list)
{
    if (list != NULL)
    {
        element_t *el = list->head;
        while (el)
        {
            element_t *new = el->next;
            free(el);
            el = new;
        }
        free(list);
    }
}

element_t *element_create(int i)
{
    element_t *el = malloc(sizeof(element_t));
    if (el)
    {
        el->val = i;
        el->next = NULL;
    }
    return el;
}

int list_append(list_t *list, int i)
{
    if (list)
    {
        element_t *el = element_create(i);
        element_t *current = list->head;

        if (list->head == NULL)
        {
            list->head = el;
        }

        if (list->tail)
        {
            list->tail->next = el;
        }
        list->tail = el;
        return 0;
    }

    return 1;
}

int list_prepend(list_t *list, int i)
{
    element_t *el = element_create(i);

    if (el)
    {
        if (list->tail == NULL)
            list->tail = el;
        if (list->head)
            el->next = list->head;
        list->head = el;
    }
    return 0;
}

element_t *list_index(list_t *list, unsigned int i)
{
    if (list->head == NULL)
    {
        return NULL;
    }

    element_t *current = list->head;

    int count = 0;
    while (count < i)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        current = current->next;
        count++;
    }

    return current;
}

void list_print(list_t *list)
{
    if (list != NULL)
    {
        element_t *el = list->head;
        {
            while (el)
            {
                printf("%d\t", el->val);
                el = el->next;
            }
        }
    }
}
