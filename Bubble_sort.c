#include <stdio.h>

int main(){
    int arr[100],size,i,j,temp;

    printf("Enter number of element : ");
    scanf("%d",&size);

    printf("Enter %d element : \n",size);
    for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
    }


    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
           if(arr[j]>arr[j+1]){
               temp = arr[j];
               arr[j]= arr[j+1];
               arr[j+1]= temp;

           }
        }
    }
    printf("\nSorted array in ascending order : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nSorted array in descending order : ");
    for(int i=size-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}