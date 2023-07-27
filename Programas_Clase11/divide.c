/* divide.c : It is a program to show the difference between an integer and a 
              floating-point division

Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>

Usage: Simple execution, no arguments

Rev History: V1.0 07/07/2009

*/

#include <stdio.h>

int main (void)
{

  printf ("\nThe integer division 6/5 is equal to %d\n", 6/5);
  printf ("The integer division 5/6 is equal to %d\n", 5/6);
  printf ("The float division 2.5/.7 is equal to %.2f\n", 2.5/.7);
  printf ("The float division .5/.7 is equal to %.2f\n", .5/.7);
  printf ("The mixed division 4/2.9 is equal to %.2f\n\n", 4/2.9);

  return 0;

}