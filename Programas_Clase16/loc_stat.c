/* loc_stat.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: using a local static variable 
*/

#include <stdio.h>
#include <stdlib.h>

void trystat (void);

int main (void)
{
  int count;
   
  for (count = 1; count <= 3; count++)
  {
    printf("Here comes iteration %d: \n", count);
    trystat();
  }
  
  system("pause");
  return 0;
}  

void trystat (void)
{
  int fade = 1;
  static int stay = 1; // 0 by default
  
  printf("fade = %d and stay = %d\n", fade++, stay++);
}
