/* circle.c : It is a program to show the use of symbolic constants

Author: Carlos H. Mendoza C.
Usage: Input the radius of a circle to calculate its area and its perimeter

Rev. History: v1.0 05/07/2009

*/

#include <stdio.h>

#define PI 3.1416

int main (void)
{
  float area, perimeter, radius;
  
  printf("Please, input the radius of the circle: ");
  scanf("%f", &radius);

  area = PI * radius * radius;
  perimeter = 2 * PI * radius;

  printf("The circle has an area equal to %f and a perimeter equal to %f\n", area, perimeter);

  return 0;

}
