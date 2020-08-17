#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

//tests list_create
int test_list_create()
{
    // test the create function
    list_t *list = list_create();

    // check to see if the create function did everything it was supposed to
    if (list == NULL)
    {
        printf("create: create failed to malloc\n");
        return 1;
    }

    if (list->head != NULL)
    {
        printf("create: head is not null!\n");
        return 1;
    }

    if (list->tail != NULL)
    {
        printf("create: tail is not null!\n");
        return 1;
    }

    return 0;
}

//test element_create
int test_element_create()
{
    element_t *el = malloc(sizeof(element_t));
    int val = 7837;
    if (el == NULL)
    {
        puts("element_create : could not set up for test");
        return 1;
    }
    memset(el, 0xFF, sizeof(element_t));
    free(el);

    el = element_create(val);

    if (el->next)
    {
        puts("element_create: element next is not null");
        return 1;
    }

    if (el->val != val)
    {
        puts("element_create: element has wrong value");
        return 1;
    }
    return 0;
}

//test list_append
int test_list_append()
{
    list_t *list = list_create();
    int val3 = 735;
    list_append(list, val3);

    if (list->tail->val != val3)
    {
        puts("list_append: element was not appended to list");
        return 1;
    }

    if (list->tail->next)
    {
        puts("list_append: element next value is not null");
        return 1;
    }

    if (list->head != list->tail)
    {
        puts("list append: head should be the same as tail");
        return 1;
    }

    if (list->head == NULL || list->tail == NULL)
    {
        puts("list_append: element was not added, list is empty");
        return 1;
    }

    if (list->tail->next != NULL)
    {
        puts("list_append: wrong element was added");
        return 1;
    }

    if (list->head->next)
    {
        puts("list_append: wrong element at head");
    }
    return 0;
}

//test list prepend
int test_list_prepend()
{
    int val2 = 473;
    list_t *list = list_create();
    list_prepend(list, val2);
    if (list == NULL)
    {
        puts("list_prepend: cannot prepend to NULL list");
        return 1;
    }

    if (list->head == NULL)
    {
        puts("list_prepend: list is headless");
        return 1;
    }

    if (list->tail == NULL)
    {
        puts("list_prepend: tail should not be null");
        return 1;
    }

    if (list->tail != list->tail)
    {
        puts("list_prepend: head should be equal to tail");
    }

    if (list->head->next != NULL)
    {
        puts("list_prepend: head has no next value");
        return 1;
    }

    if (list->head->val != val2)
    {
        puts("list_prepend: element was not prepended to list");
        return 1;
    }
    return 0;
}

//test list_index
int test_list_index()
{
    list_t *list = list_create();
    list_append(list, 456);
    list_append(list, 798);
    element_t *target = list_index(list, 0);
    element_t *out_of_bounds = list_index(list, 10);
    element_t *index_inexistent = list_index(list, -1);

    if (target->val != 456)
    {
        puts("list_index: wrong element was retrieved");
        return 1;
    }

    if (target->next == NULL)
    {
        puts("list_index: wrong element with next value was retrieved");
        return 1;
    }

      if (out_of_bounds != NULL)
    {
        puts("list_index: index was out of bounds, incorrect element returned");
        return 1;
    }

    if (index_inexistent != NULL)
    {
        puts("list_index: index was below, incorrect element returned");
        return 1;
    }

    if (list == NULL)
    {
        puts("list_index: cannot search null array");
        return 1;
    }

    if (list->head == NULL && list->tail == NULL)
    {
        puts("list_index: cannot search empty array");
        return 1;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    if (test_list_create() == 1 || test_element_create() == 1 || test_list_append() == 1 || test_list_prepend() == 1 || test_list_index() == 1)
    {
        puts("Tests Failed!");
        return 1;
    }
    return 0;
}
