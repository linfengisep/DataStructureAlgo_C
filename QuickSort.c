/*
QuickSort with the time complexity of nlogn
worst case: O(n*n);
average case : O(nlogn);
*/
#include<stdio.h>
#define arrSize 10
int arrInt[arrSize]={4,18,53,29,31,33,10,2,99,30};
void printLine(int lineNbr){
   while(lineNbr >0){
      printf("*");
      lineNbr--;
   }
   printf("\n");
}

void swap(int index1,int index2){
   int temp = arrInt[index1];
   arrInt[index1]=arrInt[index2];
   arrInt[index2]=temp;
}

void display(int *ptr){
   int size=arrSize;
   printf("[");
   while(size>0){
      printf("%d ",*(ptr++));
      size--;
   }
   printf("]\n");
}
int partition(int left,int right, int pivot){
   //defint pointer;
   int leftPtr = left-1;
   int rightPtr = right;
   //here, the pivot is always the most right position value of this subarray;
   while(1){
      //when the left value smaller than pivot, then move to right, and do nothing;
      while(arrInt[++leftPtr]<pivot){
         //do nothing;
      }
      while(arrInt[--rightPtr]>pivot){
         //do nothing;
      }
      //when find left value bigger than the pivot, and the right value smaller than the pivot,
      //then go to next, exchange those two values.
      if(leftPtr>rightPtr){
         break;// if the left value move to the right of the right value,stop;
      }else{
         swap(leftPtr,rightPtr);//switch the two value
      }
      //continue the loop;
   }
   swap(leftPtr,right);
   return leftPtr;
}

void quickSort(int left, int right){
   if(right<left){ return;
   }else{
      //define a pivot
      int pivot = arrInt[right];
      //need a function to find the partition wall;
      int partitionWall = partition(left,right,pivot);
      quickSort(left,partitionWall-1);
      quickSort(partitionWall+1,right);
   }
}

int main(int argc, char const *argv[]) {
   printLine(50);
   display(arrInt);
   quickSort(0,9);
   printLine(50);
   display(arrInt);
   return 0;
}
