/**
 * @brief: Sorting an array of elements using merge sort
 * @author: EDWIN BIMELA AJONG
 * @date: 05-12-2021
 */

#include <stdio.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main(void){
    int arr[10];
    printf("Enter 10 intergers: ");
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printf("Before sort: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, 9);

    printf("\nAfter sort: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void merge(int *arr, int left, int mid, int right){
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 = right - mid;

    //create temporary arrays
    int Left[size1], Right[size2];

    for (i = 0; i < size1; i++)
        Left[i] = arr[left + i];

    for (j = 0; j < size2; j++)
        Right[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = left;

    while (i < size1 && j < size2){
        if (Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of Left[], if there are any */
    while (i < size1){
        arr[k] = Left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of Right[], if there are any */
    while (j < size2){
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right){
    if (left < right){
        int m = left + (right - left) / 2;

        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        merge (arr, left, m, right);
    }
}