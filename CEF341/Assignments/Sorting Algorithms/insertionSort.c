/**
 * @brief: Sorting an array by insertion method
 * @author: EDWIN BIMELA AJONG
 * @date: 05-12-2021
 */

#include <stdio.h>

void insertionSort(int *arr, int);

int main(void){
    int arr[10];
    printf("Enter 10 intergers: ");
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printf("Before sort: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    insertionSort(arr, 10);

    printf("\nAfter sort: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void insertionSort(int *arr, int size){
    int i, key, j;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}