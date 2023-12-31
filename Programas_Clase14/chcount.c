/* chcount.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Descritpion: use the logical AND operator 
*/

#include <stdio.h>
#define PERIOD '.'

int main (void)
{
  int ch;
  int charcount = 0;

  while ((ch = getchar()) != PERIOD)
  {
    if (ch != '"' && ch != '\'')
	charcount++;
  }
  printf("There are %d non-quote characters.\n", charcount);
  return 0;
}
