#include <stdio.h>
#include <stdlib.h>
#define size 10

void display(int *a, int *pfront, int *prear)
{
    if ((*pfront == -1) && (*prear == -1))
    {
        printf("Queue is Empty ,nothing to display\n ");
    }
    else
    {
        for (int i = *pfront; i <= *prear; i++)
        {
            printf("%d ", a[i]);
        }
    }
}
void enqueue(int *a, int *pfront, int *prear, int data)
{

    if (*prear == size - 1)
    {
        printf("Queue is full \n");
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

int dequeue(int *a, int *pfront, int *prear)
{
    int store_data;
    if (*pfront == -1)
    {
        printf("Queue is Empty \n");
    }
   
    else
    {
        store_data = a[*pfront];
        a[*pfront] = 0;
        if (*pfront == *prear)
        {
            *pfront = *prear = -1;
        }
        else
        {
            (*pfront)++;
            return store_data;
        }
    }
}

int main()
{
    int a[10];
    int choice, pfront = -1, prear = -1, data = 0;
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
            enqueue(a, &pfront, &prear, data);
            break;

        case 2:
            data = dequeue(a, &pfront, &prear);
            printf("Deleted data : %d \n", data);
            break;

        case 3:
            display(a, &pfront, &prear);
            break;
        default:
            printf("Enter a valid choice\n ");
        }
    }
    return 0;
}