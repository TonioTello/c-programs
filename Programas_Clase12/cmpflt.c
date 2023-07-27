/* cmpflt.c
Author: Stephan Prata, from C Primer Plus
Description: Shows the use of relational operators with floating-point numbers
*/

#include <math.h>
#include <stdio.h>

int main(void)
{
  const double ANSWER = 3.14159;
  double response;

  printf("What is the value of pi?\n");
  scanf("%lf", &response);
  while (fabs(response - ANSWER) > 0.0001)
  {
    printf("Try again!\n");
    scanf("%lf", &response);
  }
  printf("Close enough!\n");
  return 0;
}
