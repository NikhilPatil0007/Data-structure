
#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct Node * next;
};
void printlist(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d /n",ptr->data);
        ptr=ptr->next;

    }

}
void main()
{
    struct Node * head;
    struct Node * seacond;
    struct Node * third;
    head=(struct Node *)malloc(sizeof(struct Node));
    seacond=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->next=seacond;
    seacond->data=10;
    seacond->next=third;
    third->data=90;
    third->next=NULL;
    printlist(head);

}
