/**
 * @brief: implementing a stack using linked list
 * @author: EDWIN BIMELA AJONG
 * @date: 01-31-2021
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *push(struct node *);
void pop(struct node **);
void display(struct node *);
void sizeOfStack(struct node *);
void topOfStack (struct node *);

int main(void){
    int command;
    struct node *head;
    head = NULL;

    for(;;){
        printf("Enter command: ");
        scanf("%d",&command);
        switch(command){
            case 1:
                head = push(head);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                sizeOfStack(head);
                break;
            case 5:
                topOfStack(head);
                break;
            case 6:
                printf("Quiting...\n");
                return 0;
            default:
                printf("Invalid Input\n");
        }
    }

    return 0;
}

struct node *push(struct node *list){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    if(new_node == NULL){
        printf("No more memory, Quiting....\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter number to add to stack: ");
    scanf("%d", &(new_node->value));

    new_node->next = list;
    return new_node;
}

void pop(struct node **head){
    struct node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(struct node *list){
    printf("Stack: ");
    while (list->next != NULL){
        printf("%d->", list->value);
        list = list->next;
    }
    printf("%d\n", list->value);
}

void sizeOfStack(struct node *list){
    int count = 0;
    while(list != NULL){
        count++;
        list = list->next;
    }
    printf("Number of elements in stack: %d\n", count);
}

void topOfStack(struct node *head){
    printf("Element at top of stack: %d\n", head->value);
}