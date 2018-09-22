#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *leftChild;
   struct Node *rightChild;
};
struct Node *root = NULL;

void insert(int data){
   struct Node *parent;
   struct Node *tempNode = (struct Node*) malloc(sizeof(struct Node));
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;
   if(root == NULL){
      root = tempNode;
   }else{
      parent = root;
         while(1){
         if(data > parent->data){
            if(parent->rightChild == NULL){
               parent->rightChild = tempNode;
               //printf("check data:%d\n",tempNode->data);
               return ;//when return,the next code won't be executed;
            }
               parent=parent->rightChild;
         }else{
            if(parent->leftChild == NULL){
               parent->leftChild = tempNode;
               return ;
            }
               parent=parent->leftChild;
         }
      }
   }
}

struct Node* search(int data){
   struct Node* parent;
   if(root->data == data){
      return root;
   }else{
      parent = root;
      while(parent->data !=data){
         if(data < parent->data){
            if(parent->leftChild !=NULL){
               parent = parent->leftChild;
            }else{return NULL;}
         }else{
            if(parent->rightChild !=NULL){
               parent = parent->rightChild;
            }else{return NULL;}
         }
      //printf("parent data:%d\n",parent->data);
      }
      return parent;
   }
}

void preOrderTraversal(struct Node* root){
   if(root !=NULL){
      printf("the path value:=%d\n",root->data);
      preOrderTraversal(root->leftChild);
      preOrderTraversal(root->rightChild);
   }
}
void loadingData(){
int intArr[7]={20,10,45,28,89,39,4};
   for (int i = 0; i < 7; i++) {
      insert(intArr[i]);
   }
}
int main(int argc, char const *argv[]) {
   loadingData();
   int target = 4;
   struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
   temp = search(target);
   if(temp!=NULL) {
      printf("target:%d found.\n",temp->data);
      }else{
      printf("target:%d not found.\n",target);
   }
   return 0;
}
/*
void testLoadingData(){
   printf("the value:=%d\n",(((root->rightChild)->leftChild)->rightChild)->data);
   printf("%d\n", ((root->leftChild)->leftChild)->data);
   insert(intArr[0]);
   insert(intArr[1]);
   int temp = (root->leftChild)->data;
   printf("the second value:=%d\n",temp);
   printf("the root value:=%d\n",root->data);
   insert(intArr[2]);
   printf("third value:=%d\n",(root->rightChild)->data);
   insert(intArr[3]);
   printf("third value:=%d\n",((root->rightChild)->leftChild)->data);
}
*/
