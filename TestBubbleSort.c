#include<stdio.h>
//pass by reference;
void swap(int *ptr1,int *ptr2){
   int temp=*ptr2;
   *ptr2 = *ptr1;
   *ptr1 = temp;
}

void display(int *ptr, int size){
   while(size !=0){
      printf("%d\n",*(ptr++));
      size--;
   }
}

int main(int argc, char const *argv[]) {
   int arrayToBeSorted[] = {2,10,39,5,87,20,19,33,59,0};
   int size = sizeof(arrayToBeSorted)/sizeof(arrayToBeSorted[0]);

   int j= size;
   for(int i=0;i<size-1;i++){
      for(int m=0;m<j;m++){
         if(arrayToBeSorted[m]>arrayToBeSorted[m+1]){
            swap(&arrayToBeSorted[m],&arrayToBeSorted[m+1]);
         }
      }
      j--;
   }
   display(arrayToBeSorted,size);
   return 0;
}
