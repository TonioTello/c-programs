/* break.c
  Author: Stephan Prata, C Primer Plus
  Description: uses break to exit a loop 
*/

#include <stdio.h>

int main (void)
{
  float length, width;
  
  printf("Enter the length of the rectangle:\n");
  while (scanf("%f", &length) == 1)
  {
    printf("Length = %.2f\n", length);
    printf("Enter its width:\n");
    if (scanf("%f", &width) != 1){
	printf("Error: You enter an invalid width\n");
	break;
    }
    printf("Width = %.2f\n", width);
    printf("Area = %.2f\n", length * width);
    printf("Enter the length of the rectangle:\n");

  }   
  printf("Bye bye.\n");  
  return 0;
}