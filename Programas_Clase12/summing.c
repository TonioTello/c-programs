/* summing.c : sums integers entered interactively
Author: Stephan Prata, from C Primer Plus, fifth edition
Usage: Input integers to be summed and type q to quit
*/

#include <stdio.h>

int main (void)
{
  long num, sum;
  int status; //to be commented
  
  sum = 0;

  printf("Please, enter an integer to be summed ");
  printf("(q to quit): ");
  status = scanf("%ld", &num);//to be commented
  
  //2nd:while (status = 1)
  //while (scanf("%ld", &num) == 1)
  while (status == 1) //to be commented
  {
    sum = sum + num;
    printf("Please, enter the next integer (q to quit): ");
    status = scanf("%ld", &num);//to be commented
  }
  printf("Those integers sum %ld\n", sum);
  return 0;
}