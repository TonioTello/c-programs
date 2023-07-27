/* misuse.c 
  Author: Stephan Prata, C Primer Plus, fifth Edition
  Description: uses a function incorrectly, this show the importance of function declaration. Compare with proto.c!!!
  Usage: Run this program several times and see the effect. 
*/

#include <stdio.h>

int imax(); /* Pre-ANSI, old-style declaration */

int main(void)
{
  printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));
  printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
  return 0;
}

int imax(n, m)
int n, m;
{
  int max;
  if (n > m)
    max = n;
  else
    max = m;
  return max; 
}
