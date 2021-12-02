/**
 * @brief: implementing selection sort on an unsorted array
 * @date: 2-31-2021
 * @author: EDWIN BIMELA AJONG
 */

#include <stdio.h>

#define SIZE 10

void swap(int *, int *);
void selection_sort(int *, int);

int main(void){
    int arr[SIZE];
    printf("Enter 10 values: ");
    for(int i = 0; i < 10;i++)
        scanf("%d", &arr[i]);
    
    printf("Array before sort: ");
    for(int i = 0; i < 10;i++)
        printf("%d ", arr[i]);
    
    selection_sort(arr, SIZE);

    printf("\nArray after sort: ");
    for(int i = 0; i < 10;i++)
        printf("%d ", arr[i]);

    return 0;
}

//function that performs the swap(by reference)
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int size){
    int minIndex;
    for(int i = 0;i < size-1; i++){
        minIndex = i;

        for(int j = i+1;j < size;j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(&arr[minIndex], &arr[i]);
    }
}