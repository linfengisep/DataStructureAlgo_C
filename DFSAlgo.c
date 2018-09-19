/*
DFS:depthward motion,uses stack to remember the vertex
in order to explore the adjacent vertex;
depth first search;
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 5

struct Vertex{
   bool visited;
   char label;
};

int stack[max];
int top = -1;
//try the matrix;
int adjMatrix[max][max];
//array of vertex;
struct Vertex* listVertex[max];
//count of vertex;
int nbrVertex=0;

void push(int item){stack[++top]=item;}
int pop(){return stack[top--];}
int peek(){return stack[top];}
bool isEmpty(){return top == -1;}

void addEdge(int start, int end){
   adjMatrix[start][end]=1;
   adjMatrix[end][start]=1;
}
void addVertex(char vertexLabel){
   struct Vertex * vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
   vertex->label = vertexLabel;
   //printf("label is:%c\n",vertex->label);
   vertex->visited = false;
   //printf("visited?:%d\n",vertex->visited);
   listVertex[nbrVertex++] = vertex;
}
//get the unvisited vertex;
int getAdjNotVisitedVertex(int vertextIndex){
   int i;
   for(i=0;i<nbrVertex;i++){
      //printf("adjMatrix[%d][%d]:%d, listVertex[%d]->visited:%d\n",vertextIndex,i,adjMatrix[vertextIndex][i],vertextIndex,listVertex[i]->visited);
      if(adjMatrix[vertextIndex][i] == 1 && listVertex[i]->visited == false){
         return i;
      }
   }
   return -1;
}

void displayVertex(int index){
   printf("%c ",listVertex[index]->label);
}

void depthFirstSearch(){
   int i;
   listVertex[0]->visited = true;
   //printf("first vertext visited? %d\n",listVertex[0]->visited);
   displayVertex(0);
   //push this original vertex indew to the stack;
   push(0);
   while(!isEmpty()){
      int unvisitedVertexIndex = getAdjNotVisitedVertex(peek());
      if(unvisitedVertexIndex == -1){
         pop();
      }else{
         listVertex[unvisitedVertexIndex]->visited = true;
         //printf("there should be label below");
         displayVertex(unvisitedVertexIndex);
         push(unvisitedVertexIndex);
      }
   }
   //when stack is empty;
   for(int i=0;i<nbrVertex;i++){
      listVertex[i]->visited = false;
   }
}

void loadingData(){
   addVertex('Z');
   addVertex('A');
   addVertex('B');
   addVertex('C');
   addVertex('D');

   addEdge(0,1);//0-A
   addEdge(0,2);//0-B
   addEdge(0,3);//0-C
   addEdge(1,4);//A-D
   addEdge(2,4);//B-D
   addEdge(3,4);//C-D
}
void displayMatrix(int size){
   for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
         printf("adjMatrix[%d][%d]:%d\n",i,j,adjMatrix[i][j]);
      }
   }
}
int main(int argc, char const *argv[]) {
   //set matrix all 0 to begin;
   for(int i=0;i<max;i++){
      for(int j=0;j<max;j++){
         adjMatrix[i][j]=0;
         }
   }
   loadingData();
   //displayMatrix(max);
   depthFirstSearch();
   return 0;
}
