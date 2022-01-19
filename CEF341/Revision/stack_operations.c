#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *push(stack *S, int x)
{
    stack *new_node;
    new_node = malloc(sizeof(stack));
    new_node->data = x;
    new_node->next = S;
    S = new_node;

    return new_node;
}

stack *pop(stack *S)
{
    if (S == NULL)
        printf("Nothing to pop\n");

    else
    {
        stack *temp;
        temp = S;
        S = S->next;
        free(temp);
        return S;
    }
}

void top(stack *S)
{
    if (S == NULL)
        printf("Nothing to diplay\n");
    else
        printf("Top of list: %d\n", S->data);
}

void reverse_print(stack *S)
{
    if (S == NULL)
        return;
    reverse_print(S->next);
    printf("%d ", S->data);
}

void display(stack *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void swap(stack *a, stack *b)
{
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

stack *bubbleSort(stack *head)
{
    stack *ptr, *ptr2;
    ptr2 = NULL;

    int swapped;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next != ptr2)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
            
        }
        ptr2 = ptr;
    } while ((swapped));
    

    return head;
}

int main(void)
{
    stack *head;
    head = NULL;

    for (int i = 0; i < 10; i++)
    {
        int x;
        printf("Enter a number: ");
        scanf("%d", &x);
        head = push(head, x);
    }

    // top(head);
    // head = pop(head);
    // top(head);
    // head = pop(head);
    // head = pop(head);
    // head = pop(head);
    // head = pop(head);
    // top(head);
    // reverse_print(head);
    display(head);
    head = bubbleSort(head);
    display(head);

    printf("\n");
    return 0;
}