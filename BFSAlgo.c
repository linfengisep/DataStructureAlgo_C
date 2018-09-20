/*
1.how to implement the queue in c?
2.the entity are the same for vertex and edge
3.only the DFS->BFS i think;
notive:
for queue,element is pushed from end point and pop out from front;

what can i put in the queue?
of course the vertex;
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 5
//define a struct to represent the vertex
struct Vertex{
   char label;
   bool isVisited;
};

//need a queue;
int front=0,rear=0;
int itemIndex=0;
int queue[max];
struct Vertex* listVertex[max];
int adjMatrix[max][max];

int peek(){
   return queue[front];
}
bool isEmpty(){
   return itemIndex==0;
}
bool isFull(){
   return itemIndex == max;
}
int insert(int data){
   if(isFull()){
      printf("the queue is full, can not insert %d\n",data);
      return 0;
   }else{
      queue[rear++]=data;
      itemIndex++;
      return 1;
   }
}

int removeData(){
   if(isEmpty()){
      printf("the queue is empty\n");
      return 0;
   }else{
      return queue[front++];
      itemIndex--;
   }
}

void addVertex(char label){
   //create a vertex from label, and put it in the queue;
   struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
   //return type of malloc is void* ,return data type unknown,so it need be casted
   vertex->label = label;
   vertex->isVisited = false;
   //do i need put this vertex in the listVertex???? yes
   //printf("vertex label %c is visited %d, and itemIndex:%d, vertexIndex:%d\n",vertex->label,vertex->isVisited,itemIndex,vertexIndex);
   listVertex[itemIndex++]=vertex;
}

int getNotVisitedVertex(){
   //pop the item out of the list vertex;
   if(isEmpty()){
      printf("the queue is empty,so all vertex are visited\n");
      return -1;
   }else{
      return removeData();
   }
}

int BFSSearch(){
   //find the one and pop

}
void addEdge(int start,int end){
   adjMatrix[start][end]=1;
   adjMatrix[end][start]=1;
}
void loadingData(){
   addVertex('S');
   addVertex('A');
   addVertex('B');
   addVertex('C');
   addVertex('D');

   addEdge(0,1);
   addEdge(0,2);
   addEdge(0,3);
   addEdge(1,4);
   addEdge(2,4);
   addEdge(3,4);
}
void display(){
   for(int i=0;i<max;i++){
      for(int j=0;j<max;j++){
         printf("[%d][%d]:%d\n",i,j,adjMatrix[i][j]);
      }
   }
}

int main(int argc, char const *argv[]) {
   for(int i=0;i<max;i++){
      for(int j=0;j<max;j++){
         adjMatrix[i][j]=0;
      }
   }

   loadingData();
   display();
   return 0;
}
