// Simple C program for pointer

#include<stdio.h>
void update(int *val){
    *val=*val*2;
}

void swap(int *pNum1,int *pNum2){
    int temp=*pNum1;
    *pNum1=*pNum2;
    *pNum2=temp;
}

void swapNumber(){
    int number1=3;
    int number2=5;
    printf("\nBefore swapping number1=%d and number2=%d",number1,number2);
    swap(&number1,&number2);
    printf("\nAfter swapping number1=%d and number2=%d",number1,number2);

}

void singlePointer(){
    int number=10;          //variable
    int* pNumber=&number;   //single pointer:special which stores the address of other variable
    int** ppNumber=&pNumber;  //double pointer:stores the address of pointer

    printf("\nvalue of number %d",number);
    printf("\naddress of number %p",&number);
    printf("\naddress of number %p",pNumber);
    printf("\naddress of number %p",ppNumber);

    printf("\nvalue of number before updating %d",number);
    update(&number);
    printf("\nvalue of number after updating %d",number); 
}


int main(){
    singlePointer();
    swapNumber();
}
