#include<stdio.h>
void swap(int *xp,int *yp){   //using pointer to change the value of two case in the array;
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void bubbleSort(int arr[], int n){
   int i,j;
   for(i = 0;i<n-1;i++)
      for(j= 0;j<n-i-1;j++)
         if(arr[j]> arr[j+1])
            swap(&arr[j],&arr[j+1]); //address if the pointer;
}

void printArray(int arr[],int size){ //printf to output the array value, "%d" for the numbers;
   int i;
   for(i=0;i<size;i++)
      printf("%d ",arr[i]);
   printf("n");
}

int main(){
   int arr[] ={12,20,30,17,2,9,89}; //initilzation of array;
   int n = sizeof(arr)/sizeof(arr[0]);  //get the size of the array; sizeof(Array)
   bubbleSort(arr,n);
   printf("Sorted array:\n");

   printArray(arr,n);
   return 0;  //for c return 0 is necessary;
}
