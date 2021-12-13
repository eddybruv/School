/**
 * @brief: Quicksort algorithm from geeksforgeeks
 */

#include <stdio.h>

void swap(int *, int *);
void quicksort(int *, int, int);
int partition(int *, int, int);

int main(void){
    int arr[10];
    printf("Enter 10 intergers: ");
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printf("Before sort: ");
    for(int i = 0; i < 10; i++)
        printf("%d", arr[i]);

    quicksort(arr, 0, 9);

    printf("\nAfter sort: ");
    for(int i = 0; i < 10; i++)
        printf("%d", arr[i]);
}