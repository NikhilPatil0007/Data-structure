#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int element, Index, store, size = 10;

    //   Sorted array for Binary Search
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 66, 99};
    
    printf("\n1.Binary iterative search\n");

    printf("\nEnter the data you want to search : ");
    scanf("%d", &element);
    store = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, store);

    return 0;
}