#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemAccount=0;

int peek(){
   return intArray[front];
}

bool isEmpty(){
   return itemAccount == 0;
}

bool isFull(){
   return itemAccount == MAX;
}

int size(){
   return itemAccount;
}

void insert(int data){
   if(!isFull()){
      intArray[++rear] = data;
      itemAccount++;
   }else{
   printf("the queue is full\n");
   }
}

int removeData(){
   if(!isEmpty()){
      itemAccount--;
      return intArray[++front];
   }else{
   printf("the queue is empty\n");
   }
}

int main(int argc, char const *argv[]) {
   insert(19);
   insert(23);
   insert(38);
   insert(40);
   insert(56);
   if(!isFull()) printf("the queue is not full.\n");
   insert(66);
   printf("************************************\n");
   int removData=removeData();
   printf("removing out the data:%d\n",removData);
   insert(76);
   insert(80);
   insert(99);
   printf("************************************\n");
   while(!isEmpty()){
      removeData();
      printf("the element at front position:%d\n",peek());
   }
   return 0;
}
