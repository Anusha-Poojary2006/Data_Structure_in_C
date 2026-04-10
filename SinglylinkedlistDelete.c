// Simple C program to delete node in a singly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory is not allocated\n");
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

//Insert at given position 

void insertAtPosition(int data,Node** head,int position){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if(position==1){
        insertAtStart(data,head);
        return;
    }
    Node* currentNode=*head;
    int currentPosition=1;
    while((currentPosition<position-1)&&(currentNode!=NULL))
    {
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
}

//Delete at start

void deleteAtStart(Node** head){
    if(*head==NULL){
            printf("List is empty\n");
            return;
        }
    Node* temp=*head;
    *head=(*head)->next;
    free(temp);
}

//Delete at End

void deleteAtEnd(Node** head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    Node* currentNode=*head;
    while(currentNode->next->next!=NULL){
        currentNode=currentNode->next;
    }
    free(currentNode->next);
    currentNode->next=NULL;
}

//Delete at position

void deleteAtPosition(Node** head,int position){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if(position==1){
        deleteAtStart(head);
        return;
    }
    int currentPosition=1;
    Node* currentNode=*head;
    
    while(currentPosition<position-1&&currentNode!=NULL){
        currentPosition++;
        currentNode=currentNode->next;
    }
    if(currentNode==NULL){
        printf("can't insert at this position,there are less nodes\n");
        return;
    }
    Node* temp=currentNode->next;
    currentNode->next=temp->next;
    free(temp);
}

//Delete value

void deleteValue(Node** head,int data){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    if((*head)->data==data){
        Node* temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    if((*head)->next==NULL){
        printf("Node doesn't exist with data %d\n",data);
        return;
    }
    Node* finder=*head;
    Node* follower=NULL;
    while(finder->next!=NULL){
        follower=finder;
        finder=finder->next;
        if(finder->data==data){
            follower->next=finder->next;
            free(finder);
            finder=NULL;
            return;
        }  
    }
    printf("Node doesn't exist with data %d\n",data);
}

//Print list

void printList(Node* head){
    Node* currentNode=head;
    if(head==NULL){
        printf("No elements to display");
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
    insertAtEnd(5,&head);
    printList(head);
    insertAtPosition(100,&head,3);
    printList(head);
    deleteAtStart(&head);
    printList(head);
    deleteAtEnd(&head);
    printList(head);
    deleteAtPosition(&head,4);
    printList(head);
    deleteValue(&head,300);
    printList(head);
}
