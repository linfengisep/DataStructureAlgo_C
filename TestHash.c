#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
struct Dataitem{
   int data;
   int key;
};

struct Dataitem * hashArray[SIZE];
struct Dataitem * tempItem;
void printLine(int lineNumber){
   for(int i=0;i<lineNumber;i++){
      printf("*");
   }
   printf("\n");
}

int hashCode(int key){
   return key%SIZE;
}

struct Dataitem* searchByKey(int keyOfItem){
   int indexOfItem = hashCode(keyOfItem);
   while(hashArray[indexOfItem] !=NULL){
      if(hashArray[indexOfItem]->key == keyOfItem){
         return hashArray[indexOfItem];
      }else{
         indexOfItem++;
         indexOfItem %= SIZE;
      }
   }
   return NULL;
}

void insertData(int key,int data){
   struct Dataitem* item = (struct Dataitem*)malloc(sizeof(struct Dataitem));
   item->key=key;
   item->data=data;
   //get the hash;
   int index = hashCode(key);
   //data isn't empty, and this item isn't dummy item;
   while(hashArray[index]!=NULL && hashArray[index]->key !=-1){
      //go to next cell;
      ++index;
      index %= SIZE;
   }
   hashArray[index]=item;
   printf("insert item-> key:=%d,data:=%d\n",key,data);
}

void deleteDataByKey(int key){
   struct Dataitem * dummyItem = (struct Dataitem*)malloc(sizeof(struct Dataitem));
   dummyItem->key = -1;
   dummyItem->data = -1;
   printf("dummy item:(%d,%d)\n",dummyItem->key,dummyItem->data);
   int indexItemDeleted = hashCode(key);
   while(hashArray[indexItemDeleted]!=NULL){
      if(hashArray[indexItemDeleted]->key == key){
         hashArray[indexItemDeleted] = dummyItem;
      }else{
         indexItemDeleted++;
         indexItemDeleted %= SIZE;
      }
   }
}

void display(){
   int i=1;
   while(i<SIZE){
      if(hashArray[i] !=NULL){
         printf("(key:%d,value:%d)\n",hashArray[i]->key,hashArray[i]->data);
      }else{
         printf("(null,null)\n");
      }
      i++;
   }
}
void loadData(){
   insertData(1,12);
   insertData(2,3);
   insertData(22,23);
   insertData(42,43);
   insertData(10,34);
   insertData(12,54);
   insertData(13,4);
   insertData(15,22);
   insertData(5,11);
   insertData(6,18);
   insertData(14,4);
   insertData(11,54);
   insertData(19,4);
   insertData(18,21);
}
int main(int argc, char const *argv[]) {
   loadData();
   printLine(40);
   display();
   printLine(40);
   tempItem = searchByKey(6);
   if(tempItem !=NULL){
      printf("search 6,its values is:=%d\n",tempItem->data);
   }else{
      printf("item not found\n");
   }

   deleteDataByKey(6);
   printLine(40);
   tempItem = searchByKey(6);
   if(tempItem !=NULL){
      printf("search 6,its values is:=%d\n",tempItem->data);
   }else if(tempItem == NULL || tempItem->key == -1 || tempItem->data == -1){
      printf("item not found\n");
   }
   return 0;
}
