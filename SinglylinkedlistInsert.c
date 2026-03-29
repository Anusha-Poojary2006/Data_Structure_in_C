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

//Insert at start
 
void insertAtStart(int data,Node** head){
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    temp->next=*head;
    *head=temp; 
}

//Insert at End

void insertAtEnd(int data,Node** head){
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
}

//Searching for key

void searchKey(Node *head,int key){
    Node* currentNode=head;
    if(currentNode==NULL){
        printf("List is empty");
    }
    while(currentNode!=NULL){
        if(currentNode->data==key){
            printf("Key found");
            return;
        }
        currentNode=currentNode->next;
    }
    printf("Key not found");
}

//Print list

void printList(Node* head){
    Node* currentNode=head;
    if(head==NULL){
        printf("No elements to display");
        return;
    }
    printf("\nhead->");
    while(currentNode!=NULL){
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head=NULL;
    head=create(10);
    insertAtStart(2,&head);
    insertAtStart(3,&head);
    insertAtStart(1,&head);
    printList(head);
    searchKey(head,3);
    insertAtEnd(5,&head);
    printList(head);
}
