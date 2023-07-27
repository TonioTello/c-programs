/* badcount.c : It is a program to show the incorrect use of printf() function

Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>

Usage: Simple execution, no arguments...discover the errors!
Rev. History : v1.0 04/07/2009
*/

#include <stdio.h>

int main (void)
{
  int centimeters = 25;
  float inches;

  inches = centimeters/2.54;
  
  printf("%f inch is equal to %d centimeters...", 2.54);
  printf("so, %d centimeters are equal to %.2f inches...", centimeters, inches);
  printf("yes!, %f inches!\n", inches, centimeters);

  return 0;
}