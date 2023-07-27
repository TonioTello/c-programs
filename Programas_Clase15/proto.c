/* proto.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Descritpion: uses an ANSI function prototype. Compare with misuse.c!!! 
*/

#include <stdio.h>

int imax(int, int); /* ANSI prototype */

int main(void)
{
  printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));
  printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
  return 0;
}

int imax(int n, int m) 
{
  int max;
  
  if (n > m)
    max = n;
  else
    max = m;
  return max;
}
