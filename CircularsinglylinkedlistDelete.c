// A simple C program to delete node in a circular singly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* newNode=(Node*) malloc (sizeof(struct node));
    if(newNode==NULL){
        printf("Memory is not allocated\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

void insertAtStart(Node** tail,int data){
    Node* temp=create(data);
    if(*tail==NULL){
        temp->next=temp;
        *tail=temp;
        return;
    }
    temp->next=(*tail)->next;
    (*tail)->next=temp;
}

void insertAtTail(Node** tail,int data){
    Node* temp=create(data);
    if(*tail==NULL){
        temp->next=temp;
        *tail=temp;
        return;
    }
    temp->next=(*tail)->next;
    (*tail)->next=temp;
    *tail=temp;
}

void deleteAtStart(Node** tail){
    if(*tail==NULL){
        printf("list is empty\n");
        return;
    }
    if((*tail)->next==*tail){
        free(*tail);
        *tail=NULL;
        return;
    }
    Node* temp=(*tail)->next;
    (*tail)->next=temp->next;
    free(temp);
    temp=NULL;
}

void deleteAtEnd(Node** tail){
    if(*tail==NULL){
        printf("list is empty\n");
        return;
    }
    if((*tail)->next==*tail){
        free(*tail);
        *tail=NULL;
        return;
    }
    Node* currentNode=(*tail)->next;
    while(currentNode->next!=*tail){
        currentNode=currentNode->next;
    }
    currentNode->next=(*tail)->next;
    free(*tail);
    *tail=currentNode;
}

void printList(Node* tail){
    if(tail==NULL){
        printf("list is empty");
        return;
    }
    Node* currentNode=tail->next;
    do{
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;

    }while(currentNode!=tail->next);
    printf("\n");
}

int main(){
     Node* tail=NULL;
    insertAtTail(&tail,3);
    printList(tail);
    insertAtTail(&tail,4);
    printList(tail);
    insertAtStart(&tail,1);
    printList(tail);
    insertAtStart(&tail,2);
    printList(tail);
    deleteAtStart(&tail);
    printList(tail);
    deleteAtEnd(&tail);
    printList(tail);
    deleteAtEnd(&tail);
    printList(tail);
    return 0;
}