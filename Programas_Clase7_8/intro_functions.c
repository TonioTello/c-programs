/* intro_functions.c : This program calls a function to prints a proverb

Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>	
Usage: Execute without options
Rev. History: V1.0 - 16/06/2009

*/

#include <stdio.h>

void phrase (void);

int main (void)
{

  printf("Hello!\n");
  printf("A chinese proverb says: ");
  phrase();
  printf("What do you think about that?");
  return 0;

}

void phrase (void) {

  printf("Deal with the faults of others as gently as with your own.\n");

}