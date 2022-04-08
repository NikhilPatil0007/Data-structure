#include<stdio.h>
#include<stdlib.h>
int taking()
{
    int parity_bit[100],count,i,counter1=0;
    printf("Enter the values in array : \n");
    for(i=0;i<7;i++)
    {
        scanf("%d",&parity_bit[i]);
    }
    //at Sender Side

    for(i=0;i<7;i++)
    {
        if(parity_bit[i]==0 || parity_bit[i]==1)
        {
            printf(" %d ",parity_bit[i]);
        }
        else{
            printf("%d is not binary language",parity_bit[i]);
        }
    }
    //count the 1's
    for(i=0;i<7;i++)
    {
        if(parity_bit[i]==1)
        {
            count++;
        }
    }
    printf("\n number of 1's is %d",count);
    if(count%2==0)
    {
        printf("\n Parity Bits are: \n");
        parity_bit[7]=0;
        for(i=0;i<8;i++)
        {
            printf(" %d ",parity_bit[i]);
        }
    }
    else
    {
        printf("\n Parity bits are: \n");
        parity_bit[7]=1;
        for(i=0;i<8;i++)
        {
            printf(" %d ",parity_bit[i]);
        }


    }
    //at receiver Side
    for(i=0;i<8;i++)
    {
        if(parity_bit[i]==1)
        {
            counter1++;
        }
    }
    if(counter1 % 2==0)
    {
        printf("\n These Frames are accepted by Receiver " );
    }
    else
    {
        printf("\n These Frames are rejected by Receiver " );
    }

}
void main()
{
    taking();
    return 0;
}


