#include <stdio.h>
void showArray(int arr[],int size){
   printf("Array element are: \n");
   for(int i=0;i<size;i++){
      printf("the value of position \'%d\' is: %d\n",i,arr[i]);
   }
}

int main(){
   /*
      1.La is the array with N element
      2.K is the index position to be inserted
      3.Item is the element to be inserted in K position
   */
   int LA[5]={2,5,9,3,1};
   int item = 919;
   int k = 2, n=5;
   int j=n;
   //printf("%d \n",item);
   showArray(LA,5);

   n++;
   while(j>= k){
      LA[j+1]=LA[j];
      j--;
   }
   LA[k] = item;

   showArray(LA,6);
}
