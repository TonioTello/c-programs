/* rules.c
  Author: Stephan Prata
  Description: precedence test. Try to figure out what the answer is and 
		then run the program to check your answer
*/

#include <stdio.h>

int main(void)
{
  int top, score;
  
  top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
  printf("top = %d \n", top);
  return 0;
}
