#include<stdio.h>
//int arr[]={19,4,11,54,25,30,3,28,17,30,12,43,1,22};
int arr[]={19,4,11,54};
int size = sizeof(arr)/sizeof(arr[0]);
int arrTemp[4];

void display(int size, int *ptr){
   printf("[ ");
   for(int i=0;i<size;i++){
      printf("%d,",*(ptr++));
   }
   printf("]\n");
}

//define one merging function
void merge(int low, int middle, int high){
   int former,later,i;
   for(former = low,later = middle+1,i=low;former<=middle && later<=high;i++){
      //when taking it,increment its position;
   printf("before:former one:%d, later one:= %d\n",arr[former],arr[later]);
      if(arr[former]<=arr[later])
         arrTemp[i] = arr[former++];
      else
         arrTemp[i] = arr[later++];
   printf("after:choose :%d\n",arrTemp[i]);
   }
   //if there is still numbers in the former or in the back, put them in the temp array;
   while(former<=middle){
      arrTemp[i++]=arr[former++];
   }
   while(later<=high){
      arrTemp[i++]=arr[later++];
   }
   for(int i=low;i<high;i++) arr[i] = arrTemp[i];
}
//define one sort function
void sort(int low, int high){
   int middle = (high+low)/2;
   if(low<high){
      sort(low,middle);
      sort(middle+1,high);
      merge(low,middle,high);
   }else{
      return;
   }
}

int main(int argc, char const *argv[]) {
   display(size,arr);
   sort(0,3);
   printf("array after sorting\n");
   display(size,arr);
   return 0;
}
