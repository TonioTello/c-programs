/* rows2.c --- using dependent nested loops 

Author: Stephen Prata, from C Primer Plus, Fifth Edition

*/

#include <stdio.h>
#define ROWS 6
#define CHARS 6

int main (void)
{
  int row;
  char ch;

  for (row = 0; row < ROWS; row++)  //The outer loop
  { 
    for (ch = ('A' + row); ch < ('A' + CHARS + row); ch++) //The inner loop
      printf("%c", ch);
    printf("\n");
  }
  
  return 0;

}