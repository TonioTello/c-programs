/*add_one.c
  Author: Stephan Prata
  Description: incrementing: prefix and postfix 
*/

#include <stdio.h>

int main(void)
{

  int ultra = 0, super = 0;

  while (super < 5)
  {
    super++;
    printf("super = %d, ultra = %d \n", super, ultra);
    ++ultra;    
  }
  return 0;
}
