//binary search

/**
 * arr -> array to be searched
 * l -> starting point(index)/left most value
 * r -> last point(index)/ rightmost value
 * x -> number to be found
 */

int binarySearch(int arr[], int l, int r, int x){
    if(r >= 1){
        int mid = 1 + (r-1);
        if(arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
}