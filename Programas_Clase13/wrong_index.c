/* wrong_index.c
Author: Carlos Mendoza <carlosmendoza@ieee.org>
Description: It shows a effect of missusing a vector
*/

#include <stdio.h>

int main (void)
{
  float height[12];

  printf("Enter your heigth in meters: ");
  scanf("%f", &height[20000]);  //Index 20000 is out of range!!!
  printf("done!\n"); 
  
  return 0;
}