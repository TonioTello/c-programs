/* for_geo.c
Author: Stephan Prata, from C Primer Plus, fifth edition
Description: It shows the flexibility of for loop
*/

#include <stdio.h>

int main (void)
{
  double debt;

  for (debt = 100.0; debt < 150.0; debt = debt * 1.1)
    printf("Your debt is now %.2f\n", debt);
  
  return 0;
}