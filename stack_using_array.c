#include <stdio.h>
#include <stdlib.h>
#define max 10

void display(int *a, int *top)
{
	printf("\n");
    for (int i = *top; i >= 0; i--)
    {
        printf("%d \n", a[i]);
    }
	printf("\n");
}
void push(int *a, int *top, int data)
{
   
    if (*top == max - 1)
    {
        printf("STACK IS FUll");
    }
    else
    {
        (*top)++;
        a[*top] = data;
    
    }

}

int pop(int *a, int *top)
{
    
    int store;
    if (*top == -1)
    {
        printf("STACK IS EMPTY,NOTHING TO DELETE \n");
    }
    else
    {
        store = a[*top];
        (*top)--;

        return store;
    }
}

int main()
{
    int a[max];

    int choice, data = 0;
    int top = -1;
    printf("1.push\n2.pop\n3.display\n");

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the data to add : \n");
            scanf("%d", &data);
            push(a, &top, data);
            break;

        case 2:
            data = pop(a, &top);
            printf("Deleted data : %d \n", data);
            break;

        case 3:
            display(a, &top);
            break;
        default:
            printf("Enter a valid choice ");
            break;
        }
    }
    return 0;
}
