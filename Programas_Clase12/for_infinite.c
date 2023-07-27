/* for_infinite.c: It is a program to show basic use of for loop
Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>
Usage: Simple execution, no arguments
Rev. History: V1.0 20/07/2009
*/

#include <stdio.h>

int main (void)
{
  int count;

  for (count = 0; ; count++)
    printf ("This is an infinite loop\n");
  return 0;
}