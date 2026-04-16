// A simple program to implements a Doubly linked list using C

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
        printf("Moemory is not allocate\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    return newNode;
}

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

void insertAtPosition(Node** head,int data, int position){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if(position==1){
        insertAtStart(head,data);
        return;
    }
    int currentPosition=1;
    Node* currentNode=*head;
    while((currentPosition<position-1) && (currentNode!=NULL)){
        currentPosition++;
        currentNode=currentNode->next;
    }
    if(currentNode==NULL){
        printf("can't insert at this position,there are less nodes\n");
        return;
    }
    Node* temp=create(data);
    temp->next=currentNode->next;
    currentNode->next=temp;
    temp->prev=currentNode;
    if(currentNode->next!=NULL){
        currentNode->next->prev=temp;
    }
}

void deleteAtStart(Node** head){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
    temp=NULL;
}

void deleteAtEnd(Node** head){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    Node* currentNode=*head;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;
    }
    currentNode->prev->next=NULL;
    free(currentNode);
}

void deleteAtPosition(Node** head,int position){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if(position==1){
        deleteAtStart(head);
        return;
    }
    Node* currentNode=*head;
    int currentPosition=1;
    while((currentPosition<position-1) && (currentNode!=NULL) ){
        currentNode=currentNode->next;
        currentPosition++;
    }
    if(currentNode==NULL){
        printf("can't delete at this position,there are less nodes\n");
        return;
    }
    Node* temp=currentNode->next;
    currentNode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=currentNode;
    }
    free(temp);
    temp=NULL;
}

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
    int choice,data,position,key;
    Node* head=NULL;
    while(1){
        printf("\n-----Doubly linked list demo-----\n");
        printf("1.Insert a node at start\n");
        printf("2.Insert a node at end\n");
        printf("3.Insert a node at given position\n");
        printf("4.Delete a node at start\n");
        printf("5.Delete a node at end\n");
        printf("6.Delete a node at given position\n");
        printf("7.print list\n");
        printf("8.Exit\n\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter a data:");
                scanf("%d",&data);
                insertAtStart(&head,data);
                break;
            }
            case 2:{
                printf("Enter a data:");
                scanf("%d",&data);
                insertAtEnd(&head,data);
                break;
            }
            case 3:{
                printf("Enter a data:");
                scanf("%d",&data);
                printf("Enter a position to insert:");
                scanf("%d",&position);
                insertAtPosition(&head,data,position);
                break;
            }
            case 4:{
                deleteAtStart(&head);
                break;
            }
            case 5:{
                deleteAtEnd(&head);
                break;
            }
            case 6:{
                printf("Enter a position to delete:");
                scanf("%d",&position);
                deleteAtPosition(&head,position);
                break;
            }
            case 7:{
                printf("Elements of the list:");
                printList(head);
                break;
            }
            case 8:{
                exit(0);
                break;
            }
            default:{
                printf("Enter a valid choice");
                break;
            }
       }
    }
    return 0;
}