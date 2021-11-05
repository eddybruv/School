/**
 * implementation of a circular queue
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void createQueue(int *);
void enQueue(int *, int);
int deQueue(void);
int topOfQueue(int *);
int endOfQueue(int *);
bool isFull(int *, int *);
bool isEmpty(int *, int *);
void print_queue(int *);

int main(void){
    int front, rear, *Queue;

    createQueue(Queue);
    return 0;
}

void createQueue(int *Q){
    int n;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    Q =  (int *) malloc((sizeof(int) * n));

    if(Q == NULL)
        printf("Error: Queue wasn't created\n.");
}