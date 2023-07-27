/* while2.c
Author: Stephan Prata, from C Primer Plus, fifth edition
Usage: Find the error
*/

#include <stdio.h>

int main (void)
{
  int n = 0;
  
  while (n++ < 3);
    printf("n is %d\n", n);
 printf("That's all this program does\n");
 return 0;
}
