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
int endItemPos=-1;
int queue[max];
struct Vertex* listVertex[max];
int adjMatrix[max][max];
int nbrVertex=0;

void testMatrix(){
   for(int i=0;i<max;i++){
      for(int j=0;j<max;j++){
         printf("(%d,%d):%d)\n",i,j,adjMatrix[i][j]);
      }
   }
}
int peek(){
   return queue[front];
}
bool isEmpty(){
   return endItemPos==-1;
}
bool isFull(){
   return endItemPos == max;
}
void push(int data){
   if(isFull()){
      printf("the queue is full, can not push %d\n",data);
   }else{
      queue[rear++]=data;
      endItemPos++;
      //int po=rear-1;printf("queue[%d]:%d, data=%d\n",po,queue[po],data);
   }
}

int pop(){
      endItemPos--;
      return queue[front++];
}
void displayVertex(int index){
   printf("%c ",listVertex[index]->label);
}

void addVertex(char label){
   //create a vertex from label, and put it in the queue;
   struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
   //return type of malloc is void* ,return data type unknown,so it need be casted
   vertex->label = label;
   vertex->isVisited = false;
   //do i need put this vertex in the listVertex???? yes
   //printf("vertex label %c is visited %d, and endItemPos:%d, vertexIndex:%d\n",vertex->label,vertex->isVisited,endItemPos,vertexIndex);
   listVertex[nbrVertex++]=vertex;
}

int pushAllAdjToQueue(int vertexIndex){
   for(int i=0;i<nbrVertex;i++){
      if(adjMatrix[vertexIndex][i]==1 && listVertex[i]->isVisited == false){
         return i;
      }
   }
   return -1;
}

void BFSSearch(){
   int unvisitedVertexIndex;
   listVertex[0]->isVisited = true;

   push(0);
   displayVertex(0);

   while(!isEmpty()){
      int temp = pop();
      while((unvisitedVertexIndex = pushAllAdjToQueue(temp))!=-1){
         listVertex[unvisitedVertexIndex]->isVisited = true;
         displayVertex(unvisitedVertexIndex);
         push(unvisitedVertexIndex);
      }
   }

   for (int i=0;i < nbrVertex ;i++) {
      listVertex[i]->isVisited = false;
   }

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
/*
void testQueue(){
   push(2);
   push(5);
   push(9);
   push(1);
   push(24);
   push(87);
   push(32);
   printf("peek the queue:%d\n",peek());

   for(int i=0;i<6;i++){
      pop();
   }
}
*/
int main(int argc, char const *argv[]) {
   for(int i=0;i<max;i++){
      for(int j=0;j<max;j++){
         adjMatrix[i][j]=0;
      }
   }
   loadingData();
   BFSSearch();
   return 0;
}
