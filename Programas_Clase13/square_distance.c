/* square_distance.c -- It is a program that calculates the square distance between two coordinates (x1, y1) y (x2, y2)
Author: Carlos H. Mendoza C.
Usage: Enter the two coordinates
Rev. History: 23/07/2009
*/

#include <stdio.h>

float sq_dis (float, float, float, float);

int main (void)
{
  float sq_distance; //The square distance
  float x1, y1, x2, y2; //The coordinates
 
  printf("Enter the coordinates in this form: x1 y1 x2 y2, or q to quit: ");
  while (scanf("%f%f%f%f", &x1, &y1, &x2, &y2) == 4)
  {
    sq_distance = sq_dis(x1, y1, x2, y2);
    printf("The distance between the coordinate (%.2f, %.2f) and the coordinate (%.2f, %.2f) is %.2f\n", x1, y1, x2, y2, sq_distance);
    printf("Please, enter the next pair of coordinates or q to quit: ");
   }
   printf("Up to the next time!\n");  

   return 0;
}

float sq_dis (float a, float b, float c, float d)
{
  float distance; //The square distance
  
  distance = (c-a)*(c-a)+(d-b)*(d-b);
 
  return distance;
}


 


