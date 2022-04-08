#include <stdio.h>

void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int data, temp;
    printf("Selection sort...\n");
    for (int i = 0; i < n - 1; i++)
    {
        data = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[data])
            {
                data = j;
            }
        }

        temp = A[i];
        A[i] = A[data];
        A[data] = temp;
    }
}

int main()
{

    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    display(A, n);
    selectionSort(A, n);
    display(A, n);

    return 0;
}
