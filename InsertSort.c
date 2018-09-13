#include<stdio.h>
void display(int size,int *ptr){
   while(size !=0){
   printf("%d\n",*(ptr++));
   size--;
   }
}
int main(int argc, char const *argv[]) {
   //always make the sub array sorted; this is the goal of this sorting algorithm;
   int numbers[] = {2,10,39,5,87,20,19,33,59,0};
   int size = sizeof(numbers)/sizeof(numbers[0]);
   display(size,numbers);
   printf("******************after insert sorting********************\n");
   for(int i=0;i<size-1;i++){
      if(numbers[i]>numbers[i+1]){
         int temp = numbers[i];
         numbers[i]=numbers[i+1];
         numbers[i+1]=temp;
         for(int j=i;j>0;j--){
            if(numbers[j]<numbers[j-1]){
               int nbrTransfer = numbers[j-1];
                   numbers[j-1] = numbers[j];
                   numbers[j]=nbrTransfer;
            }else{
               break;
            }
         }
      }
   }
   display(size,numbers);
   return 0;
}
