/* first_loop.c : It is a program to introduce the use of the while loop

Author: Carlos H. Mendoza C.

Usage: Input the upper limit of the sum 1+2+3+...

Rev. History: v1.0 06/07/2009

*/

#include <stdio.h>

int main (void)
{
  int upper_limit;  //It's the upper limit of the sum
  int count = 0;  //It's a counter to control the loop
  int sum = 0;    //Save the sum

  printf("Please, enter the upper limit of the sum: ");
  scanf("%d", &upper_limit);
  
  while (count < upper_limit)
  {
    sum = sum + count;
  }
  
  printf("The sum of the first %d positive integers is equal to %d\n", upper_limit, sum);

  return 0;

}
