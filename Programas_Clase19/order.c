/* order.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: precedence in pointer operations 
*/

#include <stdio.h>
#include <stdlib.h>

int data [2] = {100, 200};
int moredata [2] = {300, 400};

int main (void)
{
  int * p1, * p2, * p3;
  
  p1 = p2 = data;
  p3 = moredata;
  
  printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
  printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
  printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
 
  system("pause"); 
  return 0;
}
