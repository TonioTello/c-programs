/* nogood.c : It is a program with errors

Author: Carlos H. Mendoza C. <carlosmendozaqieee.org>

Usage: Found the errors and then execute to verify
Rev. History: V1.0 - 16/06/2009

*/

#include <stdio.h>

int main (void)
{
int n, n2, n3;
  
/* This program has several errors */

n = 5;
n2 = n * n;
n3 = n2 * n;

printf("n = %d, n al cuadrado = %d, n al cubo = %d\n", n, n2, n3);

return 0;

}