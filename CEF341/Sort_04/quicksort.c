/**
 * @brief: quick sort algorithm implementation from notes
 * @author: Mme
 * @date: 04-31-2021
 */

#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int segmentation(int *arr, int i, int j){
    int p, q;
    int val, per;
    p = i;
    q = j;
    val = arr[j];

    while (p <= q){
        while ((arr[p] <= val) && (p <= j))
            p++;

        while((arr[q] > val) && (i <= q))
            q--;

        if(p < q)
            swap(&arr[p], &arr[q]);
    }

    return q;
}

void quicksort(int *arr, int i, int j){
    int m;

    if( i < j){
        m = segmentation(arr, i, j);

        if (m == j)
            quicksort(arr, i, m-1);
        else
            quicksort(arr, i, m);
        quicksort(arr, m+1, j);

    }
    return;
}

int main(void){
    int arr[10];
    printf("Enter 10 intergers: ");
    
    for(int i = 0; i < 10; i++)
        scanf("%d",&arr[i]);

    printf("Before sort: ");
    for(int i = 0;i < 10;i++)
        printf("%d ", arr[i]);

    quicksort(arr, 0, 9);

    printf("\nAfter sort: ");
    for(int i = 0;i < 10;i++)
        printf("%d ", arr[i]);
}