// Simple C program to insert node for Doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory is not allocated\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    return newNode;
}

//Insert at start
void insertAtStart(Node** head,int data){
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    temp->next=*head;
    (*head)->prev=temp;
    *head=temp;
}

//Insert at End
void insertAtEnd(Node** head,int data){
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    Node* currentNode=*head;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=temp;
    temp->prev=currentNode;
}

//Insert at given position
void insertAtPosition(Node** head,int position,int data){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    if(position==1){
        insertAtStart(head,data);
        return;
    }
    Node* currentNode=*head;
    int currentPosition=1;
    while((currentPosition<position-1)&&(currentNode!=NULL)){
        currentNode=currentNode->next;
        currentPosition++;
    }
    if(currentNode==NULL){
        printf("can't insert at this position,there are less nodes");
        return;
    }
    Node* temp=create(data);
    temp->next=currentNode->next;
    temp->prev=currentNode;
     if(currentNode->next!=NULL){
        currentNode->next->prev=temp; 
    }
    currentNode->next=temp;
   
}

//Print list
void printList(Node* head){
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    Node* currentNode=head;
    printf("head->");
    while(currentNode!=NULL){
        printf("%d<->",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("NULL\n");

}

int main(){
    Node* head=NULL;
    insertAtStart(&head,3);
    insertAtStart(&head,5);
    insertAtEnd(&head,7);
    printList(head);
    insertAtPosition(&head,3,100);
    insertAtPosition(&head,1,2);
    printList(head);
    insertAtPosition(&head,6,9);
    printList(head);

    return 0;
}