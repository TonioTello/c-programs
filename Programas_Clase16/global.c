/* global.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: uses an external variable 
*/

#include <stdio.h>
#include <stdlib.h>

int units = 0; /* an external variable */

void critic(void);

int main(void)
{
  extern int units; /* an optional redeclaration */
  
  printf("How many pounds to a firkin of butter?\n");
  scanf("%d", &units);
  while ( units != 56)
    critic();
  printf("You must have looked it up!\n");
  system("pause");
  return 0;
}

void critic(void)
{
/* optional redeclaration omitted */
printf("No luck, chummy. Try again.\n");
scanf("%d", &units);
}
