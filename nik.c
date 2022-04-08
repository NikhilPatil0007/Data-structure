#include<stdio.h>
int main()
{
    int arr[5],i,key,low,high,mid,n;
    printf("Enter Number of elements elements :");
    scanf("%d",&n);
    printf("Enter Array elemnts");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter value to find: ");
    scanf("%d",&key);
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(arr[mid]<key)
            low=mid+1;
        else if(arr[mid]=key){
            printf(" %d Element is found at location %d",key,mid+1);
        break;

    }
    else
        high=mid-1;
        mid=(low+high)/2;
    }
    if(low>high)
        printf("Element is not found %d",key);

    return 0;

}

