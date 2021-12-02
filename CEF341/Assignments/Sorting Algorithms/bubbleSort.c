/**
 * @brief: implementing bubble sort on an unsorted array
 * @date: 2-31-2021
 * @author: EDWIN BIMELA AJONG
 */

#include <stdio.h>

#define SIZE 10

void swap(int *, int *);
void bubble_sort(int *, int);

int main(void){
    int arr[SIZE];
    printf("Enter 10 values: ");
    for(int i = 0; i < 10;i++)
        scanf("%d", &arr[i]);
    
    printf("Array before sort: ");
    for(int i = 0; i < 10;i++)
        printf("%d ", arr[i]);
    
    bubble_sort(arr, SIZE);

    printf("\nArray after sort: ");
    for(int i = 0; i < 10;i++)
        printf("%d ", arr[i]);

    return 0;
}

void bubble_sort(int *arr, int size){
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size-1;j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

//function that performs the swap(by reference)
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
