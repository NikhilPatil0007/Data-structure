#include <stdio.h>
#include <stdlib.h>
#define MAX 10


void insert(int *a, int *pfront, int *prear, int data)
{

    if ((*prear == MAX - 1 && *pfront == 0) || (*prear + 1 == *pfront))
    {
        printf("Queue is Full\n ");
    }
    else if (*prear == MAX - 1)
    {
        *prear = 0;
        a[*prear] = data;
    }
    else
    {
        (*prear)++;
        a[*prear] = data;
        if (*pfront == -1)
        {
            *pfront = 0;
        }
    }
}

void display(int *a, int *pfront, int *prear)
{
    if (*pfront == -1 && *prear == -1)
    {
        printf("Queue is Empty ,nothing to display\n ");
    }
    else
    {

        for (int i = *pfront; i <= *prear; i++)
        {
            printf("%d ", a[i]);
        }
        if (*pfront == MAX - 1)
        {
            a[*pfront] = 0;
            for (int i = *pfront; i <= *prear; i++)
            {
                printf("%d ", a[i]);
            }
        }
        
    }
}

int delete (int *a, int *pfront, int *prear)
{
    int data;
    if (*pfront == -1)
    {
        printf("queue is Empty , nothing to delete ");
    }
    else
    {
        data = a[*pfront];
        a[*pfront] = 0;
        if (*pfront == *prear)
        {
            *pfront = -1;
            *prear = -1;
        }
        else if (*pfront == MAX - 1)
        {
            *pfront = 0;
        }
        else
        {
            (*pfront)++;
        }
        return data;
    }
}
int main()
{
    int a[10];
    int choice, pfront = -1, prear = -1, data;
    printf("1.enqueue\n2.dequeue\n3.display\n");

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the data to add : \n");
            scanf("%d", &data);
            insert(a, &pfront, &prear, data);
            break;

        case 2:
            data = delete (a, &pfront, &prear);
            printf("Deleted data : %d \n", data);
            break;

        case 3:
            display(a, &pfront, &prear);
            break;
        default:
            printf("Enter a valid choice ");
        }
    }
    return 0;
}