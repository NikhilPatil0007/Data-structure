#include<stdio.h>
void main()
{
    int array[10],i;
    printf("Enter:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    int size=10,ele;
    printf("Element:");
    scanf("%d",&ele);
    for(i=0;i<10;i++)
    {
        if(ele==array[i])
        {
            printf("Element is found At %d",i);
            break;
        }
        else{
            printf("Element is not found ");
        }
    }

}
