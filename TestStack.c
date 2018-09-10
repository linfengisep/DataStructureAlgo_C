#include<stdlib.h>
#include<stdio.h>
int MAX_SIZE=7;
int stack[7];
int top = -1;

int isEmpty(){
   if(top ==-1){
      return 1;
   }else{
      return 0;
   }
}

int isFull(){
   if(top == MAX_SIZE){
      return 1;
   }else{
      return 0;
   }
}

int peek(){
   //we can only peak the top position value, nothing else;remember LIFO;
   return stack[top];
}

int pop(){
   //pop the top value; get the value, remove it out, point the top to the below one;
   int data;
   if(!isEmpty()){
      data = stack[top];
      top = top -1;
      return data;
   }else{
      printf("%s\n","the stack is empty");
      return 0;
   }
}

int push(int data){
   if(!isFull()){
      stack[++top]=data;
   }else{
      printf("%s\n","the stack is full");
   }
   return data;
}

int main(int argc, char const *argv[]) {
   push(12);
   push(24);
   push(33);
   push(46);
   push(56);
   push(63);
   push(71);
   push(88);
   push(90);
   printf("%s\n","******************************");
   printf("the top element is: %d\n",peek());
   printf("%s\n","******************************");
   while(!isEmpty()){
      printf("remove the top element %d\n",pop());
   }
   printf("%s\n","******************************");
   printf("the stack is full? %s\n",isFull()?"true":"false" );
   printf("the stack is empty? %s\n",isEmpty()?"true":"false");
   return 0;
}
