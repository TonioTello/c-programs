/* for_13s.c
    Author: Stephan Prata
    Description: Shows the flexibility of the for loop in its third control expression
*/

#include <stdio.h>

int main(void)
{
  int n;
  for (n = 2; n < 60; n = n + 13) /* count by 13s */
    printf("%d \n", n);
  return 0;
}
