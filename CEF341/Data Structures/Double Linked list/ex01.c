/**
 * Doubly linked list implementation.
 * Source: https://www.geeksforgeeks.org/doubly-linked-list/
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


//adding a node at the front
void insertFirst(struct node **head, int data)
{
    //declare and allocate node
    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    //put data
    new_node->data = data;

    //make the next of new node as the head and the previous as NULL
    new_node->next = (*head);
    new_node->prev = NULL;

    //change prec of head to new node
    if((*head) != NULL)
        (*head)->prev = new_node;

    //move head to point to new node
    (*head) = new_node;
}

//adding a node after a given node
void insertAfter(struct node *prev_node, int data){
    //check if the given pre_node is null
    if (prev_node == NULL){
        printf("Prev node cannot be NULL");
        return;
    }

    //allocate new node
    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    //put data in the node
    new_node->data = data;

    //make next of new node as next of prev node
    new_node->next = prev_node->next;

    //make the next of prev_node as new_node
    prev_node->next = new_node;

    //make prev_node as the previous of new node
    new_node->prev = prev_node;

    //change previose of new_node's next node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

//add node at the end 
void insertLast(struct node **head, int data){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    struct node *last = *head;

    new_node->data = data;

    //new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    //if the linked list is empty, then make new_node as head
    if(*head == NULL){
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    //else travers till the last node
    while (last->next != NULL)
        last = last->next;

    //change the next of last node
    last->next = new_node;

    //make the last node as a previous of new node
    new_node->prev = last;

    return;
}