/* recur.c 
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: an ilustration of recursion 
*/

#include <stdio.h>
#include <stdlib.h>

void up_and_down(int);

int main (void)
{
  up_and_down(1);
      system("pause");
  return 0;
}

void up_and_down(int n)
{
  printf("Level %d: n location %p\n", n, &n); /* 1 */
  if (n < 4)
	up_and_down(n + 1);
  printf("LEVEL %d: n location %p\n", n, &n); /* 2 */  
}
