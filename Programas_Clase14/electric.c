/* electric.c 
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: It calculates electric bill through the if-else if-else instruction
*/

#include <stdio.h>

#define RATE1 0.12589    // rate for first 360 kwh
#define RATE2 0.17901    // rate for next 320 kwh
#define RATE3 0.20971    // rate for over 680 kwh
#define BREAK1 360.0     // first breakpoint for rates
#define BREAK2 680.0     //second breakpoint for rates

/* cost for 360 kwh */
#define BASE1 (RATE1 * BREAK1)
/* cost for 680 kwh */
#define BASE2 (BASE1 + RATE2 * (BREAK2 - BREAK1))

int main (void)
{
  double kwh; 		// kilowatt-hours used
  double bill; 		// charges

  printf ("Please enter the kwh used.\n");
  scanf("%lf", &kwh);   
  if (kwh <= BREAK1)
    bill = RATE1 * kwh;
  else if (kwh <= BREAK2)
    bill = BASE1 + (RATE2 * (kwh - BREAK1));
  else
    bill = BASE2 + (RATE3 * (kwh - BREAK2));  
  printf("The charge for %.1f kwh is $%.2f.\n", kwh, bill);  
  return 0;

}
