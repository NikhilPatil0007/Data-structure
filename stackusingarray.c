#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int arr[];
};
void push(struct stack* ptr,int val)
{
    if(ptr->top==ptr->size-1)
    {
        printf("Stack is full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack* ptr)
{
    if(ptr->top==-1)
    {
        printf("Stack is empty.");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return val;

            }

}
int main()
{
    int item;
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr[10];
    printf("Stack is Succesfullly Created  \n");
    push(sp,57);
    push(sp,56);
    push(sp,50);
    item=pop(sp);
    printf("Poped Element :%d",item);

}
