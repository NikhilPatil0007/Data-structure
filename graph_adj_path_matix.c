#include <stdio.h>
#include <stdlib.h>
 #define n 5

void main()
{
    // int n;
    // printf("Enter the size of matrix : ");
    // scanf("%d", &n);

    int adjmatrix[n][n], pathmatrix[n][n];
    int P[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter node of tree %d and %d : ", i, j);
            scanf("%d", &adjmatrix[i][j]);
        }
    }

    printf("\n Adjacency Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjmatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPath Matrix : ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((adjmatrix[i][j] == 1) || (adjmatrix[i][k] == 1 && adjmatrix[k][j] == 1))

                {
                    P[i][j] = 1;
                }
                else
                {
                    P[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }
}