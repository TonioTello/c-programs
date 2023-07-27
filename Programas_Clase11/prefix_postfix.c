/* prefix_postfix.c : It is a program to show the use of the pre-increment and
                      post-increment operators

Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>

Usage: Simple execution, no arguments

Rev. History: v1.0 06/07/2009

*/

#include <stdio.h>

int main (void)
{
  int a, b;
  int aplus, bplus;

  a = 1; b = 2;

  aplus = a++;
  bplus = ++b;
 
  printf("\n\na    aplus    b    bplus\n");
  printf("%-5d%-9d%-5d%-5d\n\n", a, aplus, b, bplus);

  return 0;

}
