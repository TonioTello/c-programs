/* type_conversions.c : It is a program to show implicit type conversions
Author: Stephan Prata, from C Primer Plus, Fifth Edition
*/

#include <stdio.h>

int main (void)
{
  unsigned char ch;
  int i;
  float fl;

  fl = i = ch = 'C';
  printf("\nch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
  ch = ch + 1;
  i = fl + 2 * ch;
  fl = 2.0 * ch + i;
  printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
  ch = 5212205.17;
  printf("Now ch = %d\n\n", ch);  
  
  return 0;
}
