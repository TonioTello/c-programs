/* input.c 
  Author: Stephan Prata
  Description: when to use &
*/
 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int age;	// variable
  float assets;	// variable
  char pet[30];	// string
  
  printf("Enter your age, assets, and favorite pet.\n");
  scanf("%d %f", &age, &assets); // use the & here
  scanf("%s", pet); // no & for char array
  printf("%d $%.2f %s\n", age, assets, pet);
  
  system("pause");
  return 0;
  
}
