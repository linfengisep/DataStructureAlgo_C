/*
MST minimum spanning tree.prim, greedy algo.
a.no circle/loop in mst. b,minimally connected. c,adding one edge will add circle.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define max 5
#define INT_MAX 2147483647
int pathMatrix[max][max];
int indexListVertice = 0;
int countMST=0;
struct Vertice{
   char label;
   bool isIncluded;//at the beginning, they are not included;
};

struct Vertice* mstVertice[max];
struct Vertice* listVertice[max];

void addEdgeWithWeight(int start,int end,int weight){
   pathMatrix[start][end]=weight;
   pathMatrix[end][start]=weight;
}
void addVertice(char label){
   struct Vertice* vertice = (struct Vertice*)malloc(sizeof(struct Vertice));
   vertice->label = label;
   vertice->isIncluded = false;
   listVertice[indexListVertice++] = vertice;
}
void loadingData(){
   addVertice('A');
   addVertice('B');
   addVertice('C');
   addVertice('D');
   addVertice('E');

   addEdgeWithWeight(0,0,0);//0-0 original point
   addEdgeWithWeight(0,1,34);//A-B
   addEdgeWithWeight(0,2,12);//A-C
   addEdgeWithWeight(0,3,29);//A-D
   addEdgeWithWeight(1,4,10);//B-E
   addEdgeWithWeight(2,4,23);//C-E
   addEdgeWithWeight(3,4,47);//D-E
}
int getMinWeightAdjVertice(){
   int minWeight = INT_MAX;
   int minWeightVerticeIndex;
   for(int i=0;i<countMST;i++){
      for(int j=0;j<max;j++){
         if(!(listVertice[j]->isIncluded)){
            int matrixWeight = pathMatrix[listVertice[j]->label-'A'][mstVertice[i]->label-'A'];
            if(minWeight > matrixWeight){
               minWeight = matrixWeight;
               minWeightVerticeIndex = j;
               }
         }
      }
   }
   return minWeightVerticeIndex;
}

void prim(){
   //init the original vertice;
   mstVertice[countMST++] = listVertice[0];
   listVertice[0]->isIncluded = true;
   //printf("mst first:%d\n",countMST);
   while(countMST != max){
      //1.pick the mim value
      int minWeightVerticePosition=getMinWeightAdjVertice();
      //2.put it in the mstVertice
      listVertice[minWeightVerticePosition]->isIncluded = true;
      mstVertice[countMST++] = listVertice[minWeightVerticePosition];
   }
   //print the path:
   printf("the path is:");
   for (int i = 0; i < countMST; i++) {
      printf("%c -> ",mstVertice[i]->label);
   }
}

int main(int argc, char const *argv[]) {
   //init the matrix with weight = infinity;
   for (int i = 0; i < max; i++) {
      for (int j = 0; j < max; j++) {
         pathMatrix[i][j]=INT_MAX;
      }
   }
   loadingData();
   prim();
   return 0;
}
