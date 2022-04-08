#include<stdio.h>
struct employee{
    int number;
    char name[10];
    char address[10];
};
void search(struct employee *e,int key)
{
    int n,i,flag=0;
    n=key%100;
    if(e[n].number==key)
    {
        e[n].number=key;
        printf("Employee name:%s\n",e[n].name);
        printf("Employee Address:%s\n",e[n].address);
        flag=1;
    }
    else{
        for(i=n+1;i<100;i++)
        {
            if(e[n].number==key)
            {
                e[i].number=key;
                printf("Employee name:%s\n",e[n].name);
                printf("Employee Address:%s\n",e[n].address);
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        for(i=0;i<n;i++)
        {
            if(e[n].number==key)
            {
                e[i].number=key;
                printf("Employee name:%s\n",e[n].name);
                printf("Employee Address:%s\n",e[n].address);
                flag=1;
            }
        }
    }
    if(flag=0)
    {
        printf("Key does not found");
    }



}
void insert(struct employee *e,int key)
{
    int n,flag=0,i;
    n=key%100;
    if(e[n].number==-1)
    {
        e[n].number=key;
        printf("Enter Employee name:");
        scanf("%s",e[n].name);
        printf("Enter Employee Address:");
        scanf("%s",e[n].address);
        flag=1;
    }
    else{
        for(i=n+1;i<100;i++)
        {
            if(e[n].number==-1)
            {
                e[i].number=key;
                printf("Enter Employee name:");
                scanf("%s",e[n].name);
                printf("Enter Employee Address:");
                scanf("%s",e[n].address);
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        for(i=0;i<n;i++)
        {
            if(e[n].number==-1)
            {
                e[i].number=key;
                printf("Enter Employee name:");
                scanf("%s",e[n].name);
                printf("Enter Employee address:");
                scanf("%s",e[n].address);
                flag=1;
            }
        }
    }
    if(flag=0)
    {
        printf("Array is Full");
    }


}
int main()
{
struct employee e[100];
int key,n,i,choice;
for(i=0;i<100;i++)
{
    e[i].number=-1;
}
while(1)
{
printf("\nEnter choice:");
scanf("%d", &choice);
if(choice<=0)
{
 break;
}
else
    {
        switch(choice)
        {
        case 1:
            {
            int key1;
            printf("Enter key:");
            scanf("%d",&key1);
            insert(&e,key1);
            break;
            }
        case 2:
            {
            int key2;
            printf("Enter key:");
            scanf("%d",&key2);
            search(&e,key2);
            break;
            }
        default:
            {
            printf("Enter Correct option\n");
            }
        }
    }

}
return 0;
}
