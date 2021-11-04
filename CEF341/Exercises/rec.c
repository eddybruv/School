#include <stdio.h>

int elt(int *arr, int size, int x);

int main(void)
{
    int n, found;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int max = arr[0];

    for(int i = 0; i < n;i++){
        if(max < arr[i])
            max = arr[i];
    }
    found = elt(arr, n, max);
    printf("%d is found at index: %d", max, found);
    return 0;
}
int elt(int *arr, int size, int x)
{
    int rec;

    size--;
    if (size >= 0)
    {
        if (arr[size] == x)
            return size;

        rec = elt(arr, size, x);
    }
    else
        return -1;
    return rec;
}