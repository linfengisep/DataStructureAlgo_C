#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
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

//insert operation;inserting element, we need create a node containing the data and the key;
void insertElement(int key,int data){
struct node *link = (Node*)malloc(sizeof(Node));
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
   Node *tempLink = head;
   head=head->next;
   return tempLink;
}
//find data in key position
Node * find(int key){
   Node* currentNode = head;
   if(head == NULL){
      return NULL;
   }else{
         while(currentNode->key !=key){
               if(currentNode->next ==NULL){
                  return NULL;
               }else{
                  currentNode = currentNode->next;
               }
         }
   }
   return currentNode;
}
//delete one element in the key position
Node* deleteFrom(int position){
   Node* current=head;
   Node* previous=NULL;
   //if list is empty;
   if(head==NULL)return NULL;
   while(current->key != position){
         if(current->next ==NULL) {
            return NULL;
         }else{
            previous = current;
            current = current->next;
         }
   }
   //found a match;
   if(current==head){
      head = head->next;
   }else{
      previous->next = current->next;
   }
   return current;
}

void loadData(){
   insertElement(1,12);
   insertElement(2,22);
   insertElement(3,39);
   insertElement(4,45);
   insertElement(5,57);
}

int main(int argc, char const *argv[]) {
   /* code */
   loadData();
   displayList();
   printf("%d\n",isEmpty());

   while(!isEmpty()){
      Node* deleteElement= deleteFirst();
      printf("delete element's position :%d, its value: %d\n", deleteElement->key,deleteElement->data);
   }
   loadData();
   printf("%d\n",find(2)->data);
   printf("%s\n","*********************************");
   printf("delete the position = 3,its value is: %d\n",deleteFrom(3)->data);
   return 0;
}
