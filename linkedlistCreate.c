#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory is not allocated");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

int main(){
    Node* temp=create(10);
}
