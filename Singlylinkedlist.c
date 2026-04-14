// A simple program to implements a singly linked list using C

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

void insertAtStart(int data,Node** head){ 
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    temp->next=*head;
    *head=temp;
}

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

void insertAtPosition(int data,Node** head,int position){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if(position==1){
        insertAtStart(data,head);
        return;
    }
    int currentPosition=1;
    Node* currentNode=*head;
    while((currentPosition<position-1)&&(currentNode!=NULL)){
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

void deleteAtStart(Node** head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    free(temp);
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
    while(currentNode->next->next!=NULL){
        currentNode=currentNode->next;
    }
    free(currentNode->next);
    currentNode->next=NULL;
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

void deleteValue(Node** head,int data){
    if(*head==NULL){
        printf("List is empty\n");
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

void searchKey(Node* head,int key){
    Node* currentNode=head;
    if(currentNode==NULL){
        printf("list is empty");
        return;
    }
    while(currentNode!=NULL){
        if(currentNode->data==key){
            printf("key found\n");
            return;
        }
        currentNode=currentNode->next;
    }
    printf("key not found\n");
}

void printList(Node* head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    Node* currentNode=head;
    printf("\nhead->");
    while(currentNode!=NULL){
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("NULL\n");
}

int main(){
    int choice,data,position,key;
    Node* head=NULL;
    while(1){
        printf("\n-----Linked list demo-----\n");
        printf("1.Insert a node at start\n");
        printf("2.Insert a node at end\n");
        printf("3.Insert a node at given position\n");
        printf("4.Delete a node at start\n");
        printf("5.Delete a node at end\n");
        printf("6.Delete a node at given position\n");
        printf("7.Delete a node by given value\n");
        printf("8.Search key in list\n");
        printf("9.print list\n");
        printf("10.Exit\n\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter a data:");
                scanf("%d",&data);
                insertAtStart(data,&head);
                break;
            }
            case 2:{
                printf("Enter a data:");
                scanf("%d",&data);
                insertAtEnd(data,&head);
                break;
            }
            case 3:{
                printf("Enter a data:");
                scanf("%d",&data);
                printf("Enter a position to insert:");
                scanf("%d",&position);
                insertAtPosition(data,&head,position);
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
                printf("Enter a value to delete:");
                scanf("%d",&data);
                deleteValue(&head,data);
                break;
            }
            case 8:{
                printf("Enter key element to search:");
                scanf("%d",&key);
                searchKey(head,key);
                break;
            }
            case 9:{
                printf("Elements of the list:");
                printList(head);
                break;
            }
            case 10:{
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





