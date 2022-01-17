//remember that position 0 is never used
#include <stdlib.h>

void merge_sort(int *arr, int p, int r){    //where p is the initial position, r is the last position
    int q;  //middle position(somewhat)
    if(p < r){
        q = p + ((r - p) / 2);
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int *arr, int p, int q, int r){
    int i, j, k, ai, aj;
    int *B;
    B = (int *)malloc(sizeof(int) * (r - p + 2));
    
    i = p;
    j = q + 1;
    ai = arr[i];
    aj = arr[j];

    for(k = 1; k <= (r - p + 1); k++){
        if (ai < aj){
            B[k] = ai;
            i++;
            if (i <= q)
                ai = arr[i];
        }
        else {
            B[k] = aj;
            j++;
            if (j <= r)
                aj = arr[j];
        }
    }

    for(k = p; k <= r; k++)
        arr[k] = B[k - p + 1];
        
    free(B);
}