#include <stdio.h>
// #include <stdlib.h>

// Binary Recursive Search
int Recursive_search(int arr[], int low, int high, int element)
{
    int mid = (low + high) / 2;

    if (low <= high)
    {

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] > element)
        {
            return Recursive_search(arr, low, mid - 1, element);
        }
        else
        {
            return Recursive_search(arr, mid + 1, high, element);
        }
    }

    return -1;
}

int main()
{
    int element, store, Index, size = 10;

    //   Sorted array for Binary Search
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 66, 99};

    printf("\n1.Binary Recursive Search\n");

    printf("\nEnter the data you want to search : ");
    scanf("%d", &element);

    store = Recursive_search(arr, 0, size - 1, element);
    printf("The element %d was found at index %d \n", element, store);

    return 0;
}