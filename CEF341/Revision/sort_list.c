#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

void swap(stack *a, stack *b)
{
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

stack *sort_list(stack *head)
{
    stack *ptr, *ptr2;
    ptr = head;
    ptr2 = head;

    while (ptr2 != NULL)
    {
        ptr = ptr2;

        while (ptr != NULL)
        {
            if (ptr->data < ptr2->data)
                swap(ptr, ptr2);
            ptr = ptr->next;
        }

        ptr2 = ptr2->next;
    }

    return head;
}