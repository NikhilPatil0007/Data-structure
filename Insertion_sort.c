#include <stdio.h>

void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{

    int A[6] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printf("Before Insertion Sort : \n");
    Display(A, n);
    insertionSort(A, n);
    printf("After Insertion Sort : \n");
    Display(A, n);
    return 0;
}
