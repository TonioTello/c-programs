/* lesser.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: It defines a function with return value. main() it's used as a DRIVER
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int number1, number2, lesser;

  printf("Please, enter a pair of integers (q to quit): ");
  while (scanf("%d %d", &number1, &number2) == 2)
  {
    lesser = imin(number1, number2);
    printf("The lesser of %d and %d is %d\n", number1, number2, lesser);
    printf("Enter a pair of integers (q to quit): ");
  } 
  printf("Bye\n");  
    system("pause");
 return 0;
}

int imin(int n, int m)
{
 int min;

 if (n > m)
    min = m;
 else 
    min = n;  
 return min;
}
