#include<stdio.h>
void main()
{
    int array[10],i,size=10,low,high,mid,ele;
    printf("Enter Array Elements:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter Value to be found:");
    scanf("%d",&ele);
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(array[mid]==ele)
        {
            printf(" %d Element is found at location %d",ele,mid);
            break;
        }
        else if(array[mid]<ele)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
            mid=(low+high)/2;

        }
    }
        if(low>high)
        {
            printf("Element is Not found");
        }


}



