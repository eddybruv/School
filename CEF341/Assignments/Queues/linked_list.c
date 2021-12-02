/**
 * @brief: implementing a queue using linked list
 * @author: EDWIN BIMELA AJONG
 * @date: 01-31-2021
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void enqueue(struct node **);
void dequeue(struct node **);
void display(struct node *);
void sizeOfQueue(struct node *);
void topOfQueue (struct node *);

int main(void){
    int command;
    struct node *head, *tracker;
    head = tracker = NULL;

    for(;;){
        printf("Enter command: ");
        scanf("%d",&command);
        switch(command){
            case 1:
                if(head == NULL){
                    enqueue(&head);
                    tracker = head;
                }
                else 
                    enqueue(&tracker);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                sizeOfQueue(head);
                break;
            case 5:
                topOfQueue(head);
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

void enqueue(struct node **list){
    struct node *new_node;
    new_node = malloc (sizeof(struct node));

    if(new_node == NULL){
        printf("No more memory, Quiting....\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter number to add to queue: ");
    scanf("%d", &(new_node->value));

    if(*list == NULL){
        *list = new_node;
        (*list)->next = NULL;
    }

    else {
        (*list)->next = new_node;
        (*list) = (*list)->next;
        (*list)->next = NULL;
    }
}

void dequeue(struct node **head){
    struct node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(struct node *list){
    printf("Queue: ");
    while (list->next != NULL){
        printf("%d->", list->value);
        list = list->next;
    }
    printf("%d\n", list->value);
}

void sizeOfQueue(struct node *list){
    int count = 0;
    while(list != NULL){
        count++;
        list = list->next;
    }
    printf("Number of elements in queue: %d\n", count);
}

void topOfQueue(struct node *head){
    printf("Element at top of queue: %d\n", head->value);
}