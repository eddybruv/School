/**
 * @brief:dichotonomous /binary search algorithm
 * @author: EDWIN BIMELA AJONG
 * @date: 04-12-2021
 */

#include <stdio.h>
#define N 10

int binarySearch(int arr[], int p, int r, int num);

int main(void) {
   int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int num;
   printf("Enter the number to search: \n");
   scanf("%d", &n);
   int index = binarySearch (arr, 0, n-1, num);
   if(index == -1){
      printf("%d is not present in the array", num);
   }else{
      printf("%d is present at index in the array", num, index);
   }
   return 0;
}

int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}