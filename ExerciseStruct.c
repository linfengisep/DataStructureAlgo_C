/*
exercise1:define one point,two point, and get their distance
exercise2:define a segment made of two point;
exercise3:test showSegment();createSegment();
*/

#include<stdio.h>
#include<math.h>
//define point structure
struct Point{
   double px;
   double py;
};
typedef struct Point point;

struct Segment{
   point p1;
   point p2;
};
typedef struct Segment segment;


void showArgumentsFromTerminal(int argc, char const *argv[]){
   /*
   1.here argc is the number of array argv;
   2.argv is the argument array;
   3.the first element is the name of the program;
   */
      for(int arg=0; arg<argc;arg++){
         printf("the %d element is:= %s\n",arg,argv[arg]);
      }
   }

point createPoint(double px,double py){
   point newPoint = {px,py};
   return newPoint;
   }

void showPoint(point p){
   printf("the x coordinate of point is:=%f\n",p.px);
   printf("the y coordinate of point is:=%f\n",p.py);
   }

double distance(point p1,point p2){
      return sqrt((p1.px - p2.px)*(p1.px - p2.px)
                + (p1.py - p2.py)*(p1.py - p2.py));
   }

segment createSegment(point A,point B){
   segment newSegment = {A,B};
   return newSegment;
   }

void showSegment(segment s){
   //coordinate
   printf("the x of frist point of segment is: %f\n",s.p1.px);
   printf("the y of frist point of segment is: %f\n",s.p1.py);
   printf("the x of second point of segment is: %f\n",s.p2.px);
   printf("the y of second point of segment is: %f\n",s.p2.py);
   //length;
   printf("the length of this segment is: %f\n",distance(s.p1,s.p2));
   }
int main(int argc, char const *argv[]) {
   showArgumentsFromTerminal(argc,argv);
   //exercise1
   showPoint(createPoint(2.3,3.5));
   printf("distance of the two point is:= %f\n",distance(createPoint(2.3,3.4),createPoint(5.3,7.4)));
   //exercise2 segment
   //exercise3 create and show segment;
   showSegment(createSegment(createPoint(1.1,2.4),createPoint(3.5,5.8)));
   return 0;
}
