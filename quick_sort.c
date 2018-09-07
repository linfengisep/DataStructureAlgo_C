#include <stdio.h>
void swap(int *px, int *py){
   int temp;
   temp = *px;
   *px = *py;
   *py = temp;
}

void printArray(int arr[], int size){
   for(int i=0; i<size ; i++){
      printf("%d ",arr[i]);
   }
}

void quickSort(int arr[], int l, int r){
   int indexValue;
   indexValue = arr[r];
   int flag = l;
      for(int i=l;i< r; i++){
         if(arr[i]<=indexValue){
               swap(&arr[i],&arr[flag]);
               flag++;//only when the change happen, change the flag;
            }
      }
   quickSort(arr,flag,r);
}

int main(){
   int arr[] = {12,34,49,20,3,76,33,56};
   int size = sizeof(arr)/sizeof(arr[0]);
   quickSort(arr,arr[0],arr[size-1]);
   printf("Sorted array: \n");
   printArray(arr,size);
   return 0;
}
