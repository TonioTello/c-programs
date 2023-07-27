/* for_down.c
  Author: Stephan Prata
   Description: Shows the flexibility of for loop*/
#include <stdio.h>
int main(void)
{
  int secs;
  for (secs = 5; secs > 0; secs--) //You can see the flexibility in the third control statement 
    printf("%d seconds!\n", secs);
  printf("We have ignition!\n");
  return 0;
}
 