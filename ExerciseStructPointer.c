#include <stdio.h>
struct point{
   double px;
   double py;
   char *point;
};

typedef struct point Point;
void fct(int *pointer){
   *pointer = 255;
   }
int main(int argc, char const *argv[]) {
   printf("%s\n","yes" );
   Point startPoint={0,0,"origin"};
   printf("size of point:= %lu\n",sizeof(Point) );
   printf("length of the bloc is:= %s\n",startPoint.point);
   //Point *pointer = malloc(sizeof(Point));
   //printf("%f\n",pointer->px);

   //test pointer
   int i=5;
   int *ptr = &i;
   *ptr=10;
   printf("%d - %d\n",i,*ptr);

   //pass by reference/address;

   fct(&i);
   printf("%d\n",i);
   return 0;
}
