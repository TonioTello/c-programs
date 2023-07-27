/* swap1.c 
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: first attempt at a swapping function 
*/

#include <stdio.h>

void interchange (int u, int v);

int main (void)
{
  int x = 5, y = 10;
    	
  printf("Originally x = %d and y = %d.\n", x, y);
  interchange(x,y);
  printf("Now x = %d and y = %d.\n", x, y);  
  return 0;	
}

void interchange(int u, int v) // define function
{
  int temp;
  //printf("Originally u = %d and v = %d.\n", u, v); //researching swap1.c
  temp = u;
  u = v;
  v = temp;
  //printf("Now u = %d and v = %d.\n", u, v); //researching swap1.c
}
