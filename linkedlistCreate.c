#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create(int data){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Memory is not allocated");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

int main(){
    node* temp=create(10);
}