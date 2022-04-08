#include <stdio.h>
#include <stdlib.h>


int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int element, Index, size = 12;


    // unsorted array for linear search linear Search
    int array[12] = {34, 54, 5, 56, 7, 7, 8, 8, 9, 90};

    printf("\nEnter the data you want to search : ");
    scanf("%d", &element);
    Index = linearSearch(array, size, element);
    printf("\nThe element %d was found at index %d \n", element, Index);

    return 0;
}