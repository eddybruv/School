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
void headOfQueue (struct node *);
void endOfQueue(struct node *tail);

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
                headOfQueue(head);
                break;
            case 6:
                endOfQueue(tracker);
                break;
            case 7:
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
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(struct node *list){
    printf("Queue: ");
    if(list == NULL){
        printf("List is empty.\n");
        return;
    }
    while (list->next != NULL){
        printf("%d->", list->value);
        list = list->next;
    }
    printf("%d\n", list->value);
}

void sizeOfQueue(struct node *list){
    int count = 0;
    if(list == NULL){
        printf("List is empty.\n");
        return;
    }
    while(list != NULL){
        count++;
        list = list->next;
    }
    printf("Number of elements in queue: %d\n", count);
}

void headOfQueue(struct node *head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Element at top of queue: %d\n", head->value);
}

void endOfQueue(struct node *tail){
    if(tail == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Element at end of queue: %d\n", tail->value);
}
