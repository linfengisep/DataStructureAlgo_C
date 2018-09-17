#include<stdio.h>
#include<stdlib.h>

struct point{
   double px;
   double py;
};
typedef struct point Point;
void showBasicDataLength(){
   printf("char : %lu octets\n", sizeof(char));
   printf("int : %lu octets\n", sizeof(int));
   printf("long : %lu octets\n", sizeof(long));
   printf("double : %lu octets\n", sizeof(double));
}

int main(int argc, char const *argv[]) {
   showBasicDataLength();
   printf("%lu\n",sizeof(Point));
   int numberFriends=0;
   int *ptr = NULL;
   printf("How many friends you have?\n");
   scanf("%d",&numberFriends);
   if(numberFriends>0){
      ptr = malloc(numberFriends*sizeof(int));
      for(int i=0;i<numberFriends;i++){
         printf("the age of number %d of your friends is?\n",i);
         scanf("%d",&ptr[i]);
      }

      //show it
      for(int j=0;j<numberFriends;j++){
         printf("their age are:=%d\n",ptr[j]);
      }
      free(ptr);
   }
   return 0;
}
