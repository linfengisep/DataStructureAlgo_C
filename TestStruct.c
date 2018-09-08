//test struct first
#include <stdio.h>

int main(){
   //define a student structure
   struct student{
      int cardNumber;
      int age;
      double heightInMeter;
   };
   //initilzation
   struct student lee={129,11,1.5};
   printf("Age of lee is:= %d\n",lee.age);
   //copie
   struct student thomas = lee;
   printf("Height of thomas is:=%f\n",thomas.heightInMeter);
   //simplification du type;
   typedef struct student Stu;
   Stu francois = lee;
   printf("cardNumber of francois is:= %d\n", francois.cardNumber);
   return 0;
}
