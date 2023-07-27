/* shoes2.c 
  Author: Stephan Prata, C Primer Plus
  Description: calculates foot lengths for several sizes 
*/

#include <stdio.h>
#define ADJUST 7.64
#define SCALE 0.325

int main(void)
{
  double shoe, foot;
  
  printf("Shoe size (men's) foot length\n");
  shoe = 2.0; //2nd: shoe = 2.0;
  while (++shoe < 18.5)	/* starting the while loop */
  {			/* start of block */
    foot = SCALE*shoe + ADJUST;
    printf("%10.1f %15.2f inches\n", shoe, foot);
    //shoe = shoe + 1.0;
    //shoe++;
    //2nd: while(++shoe < 18.5)
  } /* end of block */
  printf("If the shoe fits, wear it.\n");
  
  return 0;
}
