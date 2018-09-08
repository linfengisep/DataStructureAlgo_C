#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
typedef struct node Node;
//display list;
void displayList(){
   struct node *ptr = head;
   printf("[\n");
   while(ptr !=NULL){
      printf("key:%d; data:%d\n",ptr->key,ptr->data);
      ptr = ptr->next;
   }
   printf("]\n");
}

//insert operation;
void insertElement(int key,int data){
//create link;
//when inserting element, we need create a node containing the data and the key;
struct node *link = (struct node*)malloc(sizeof(Node));
link->key = key;
link->data = data;
//point it to old frist node;
link->next = head;
//point frist to the new first node;
head = link;
}

bool isEmpty(){
   return head==NULL;
}

//delete the first item;
struct node* deleteFirst(){
   struct node *tempLink = head;
   head=head->next;
   return tempLink;
}
int main(int argc, char const *argv[]) {
   /* code */
   insertElement(1,12);
   insertElement(2,22);
   insertElement(3,39);
   insertElement(4,45);
   insertElement(5,57);
   displayList();
   return 0;
}
