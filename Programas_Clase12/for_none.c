/* for_none.c
Author: Stephan Prata, from C Primer Plus, fifth edition
Description: You can leave one or more fields of for loop in blank
*/

#include <stdio.h>

int main (void)
{
  int ans, n;

  ans = 2;
  n = 3;
  for ( ; ans <= 25; )
    ans = ans * n;
  printf ("ans = %d, n = %d\n", ans, n);
  return 0;
}