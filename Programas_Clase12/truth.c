/* truth.c
  Author: Stephan Prata, from C Primer Plus
  Description: Shows that nonzero values are considered true and 0 is considered false
*/

#include <stdio.h>

int main(void)
{
  int n = 3;
  while (n)
    printf("%2d is true\n", n--);
  printf("%2d is false\n", n);
  n = -3;
  while (n)
    printf("%2d is true\n", n++);
  printf("%2d is false\n", n);
return 0;
}
