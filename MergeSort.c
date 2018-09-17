//time complexity is: nlog(n)
#include<stdio.h>
int arr[]={19,4,11,54,25,30,3,28,17,30,12,43,1,22};
//int arr[]={19,4,11,2};
int size = sizeof(arr)/sizeof(arr[0]);
int arrTemp[14];

void display(int size, int *ptr){
   printf("[ ");
   for(int i=0;i<size;i++){
      printf("%d,",*(ptr++));
   }
   printf("]\n");
}
void printline(int nbr){while(nbr>0){printf("*"); nbr--;} printf("\n");}
//define one merging function
void merge(int low, int middle, int high){
//merge(0,3) and[4,19,2,11];
   int former,later,i;
   //first loop: former 0; later = 2, high =3; -> arrTemp[0]=2, i=1; later 3;
   //second loop:former 0; later 3; high =3; ->arrTemp[1]= 2, i=2; former=1;
   // third loop: former 1; later 3; ->arrTemp[2] = 11; i=3; later =4;
   // last:1<=1;-> arrTemp[3] = arr[former]=19;
   //conclusion  [2,4,11,19]
   for(former = low,later = middle+1,i=low;former<=middle && later<=high;i++){
      if(arr[former]<=arr[later])
         arrTemp[i] = arr[former++];
      else arrTemp[i] = arr[later++];
   }
   while(former<=middle){
      arrTemp[i++]=arr[former++];
   }
   while(later<=high){
      arrTemp[i++]=arr[later++];
   }
   for(int i=low;i<=high;i++) arr[i] = arrTemp[i];
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
   sort(0,13);
   printf("array after sorting\n");
   display(size,arrTemp);
   return 0;
}
