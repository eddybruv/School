/**
 * implementation of a circular queue using arrays
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int createQueue(int **);
void enQueue(int *, int, int *, int *, int *);
int deQueue(int *, int *, int *, int *);
int topOfQueue(int *, int *);
int endOfQueue(int *, int *);
bool isFull(int *, int *, int *);
bool isEmpty(int *);
void display(int*, int *);

int main(void){
    int front = -1, rear = -1, *Queue, size, item;
    size = createQueue(&Queue);

    for (int i = 0; i < size;i++){
        printf("Enter number: ");
        scanf("%d", &item);
        enQueue(Queue, item, &front, &rear, &size);
    }
    
    display(Queue, &size);
    
    deQueue(Queue, &front, &rear, &size);
    deQueue(Queue, &front, &rear, &size);
    deQueue(Queue, &front, &rear, &size);
    
    int top = topOfQueue(Queue, &front);
    int end = endOfQueue(Queue, &rear);
    display(Queue, &size);
    return 0;
}

int createQueue(int **Q){
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    *Q =  (int *) malloc((sizeof(int) * size));

    if(Q == NULL)
        printf("Error: Queue wasn't created.\n");

    return size;
}

void enQueue(int *Queue, int item, int *front, int *rear, int *size){
    if(isFull(front, rear, size)){
        printf("Queue is full\n.");
        return;
    }

    //first item condition
    else if (*front == -1){
        *front = *rear = 0;
        Queue[*rear] = item;
    }

    else if(*rear == *size-1 && front != 0){
        *rear = 0;
        Queue[*rear] = item;
    }

    else 
    {
        *rear++;
        Queue[*rear] = item;
    }
}

int deQueue(int *Queue, int *front, int *rear, int *size){
    int f = *front;
    if(isEmpty(&f)){
        printf("Queue is empty.\n");
        return;
    }

    int rem = Queue[*front];
    Queue[*front] = -1;

    if(*front == *rear){
        *front = -1;
        *rear = -1;
    }

    else if (*front == *rear)
        *front = 0;

    else 
        *front ++;

    return rem;
}

void display(int *Queue,int *size){
    printf("Queue elements: ");

    for(int i = 0; i < *size;i++)
        printf("%d", Queue[i]);
}

bool isEmpty(int *front){
    if(*front == -1)
        return true;
    return false;
}

bool isFull(int *front, int *rear, int *size){
     if ((*front == 0 && *rear == *size-1) || (*rear == (*front - 1) % (*size - 1)))
        return true;
    return false;
}

int topOfQueue(int *Queue, int *front)
{
    return Queue[*front];
}

int topOfQueue(int *Queue, int *rear)
{
    return Queue[*rear];
}