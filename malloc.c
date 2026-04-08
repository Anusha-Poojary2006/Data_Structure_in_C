//  A simple C program for malloc function

#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr;
    int n=5;
    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Memory is not allocated");
        return 1;
    }
    for(int i=0;i<n;i++){
        arr[i]=i*1;
    }
    printf("Array elements:");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    free(arr);
    arr=NULL;
}

