//remember that position 0 is never used.
void insertion_sort(int *arr, int n){
    int i, j, key;

    for(j = 2; j <= n; j++){
        key = arr[j];
        /*insert arr[j] into sorted list*/
        i = j - 1;
        while((i > 0) && (arr[i] > key)){
            //shift value infront
            arr[i+1] = arr[i];
            //decrement i
            i--;
        }
        //insertion occurs (key is inserted to the prefered spot in the arr)
        arr[i+1] = key;
    }
}