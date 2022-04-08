#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int front;
    int rear;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = value;
        // printf("enqued element: %d\n", value);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;  // returing -1 if queue is Empty
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->front++;
        a = q->arr[q->front]; // storing deleted element in a then return
    }
    return a; 
}
 
int main(){
    struct queue q;
    q.size = 20;   // size of array
    q.front = q.rear = -1;  // initial queue is empty so -1
    q.arr = (int*) malloc(q.size*sizeof(int));  // memory allocation 20 *integer sizes
    
    // BFS  
    int node;
    int i = 1;    // i is the value from where to start visiting/exploring the tree 
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d ", i);
    visited[i] = 1; // now i is visited mark as 1
    enqueue(&q, i); // exploring  tree
    while (!isEmpty(&q))  // repeat until queue is empty
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){ // checking if node is connected or not and not visited
                printf("%d ", j);
                visited[j] = 1; // marking that node as visited
                enqueue(&q, j);   // exporing tree further
            }
        }
    }
    return 0;
}
