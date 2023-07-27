/* colddays.c 
  Author: Stephan Prata, C Primer Plus, Fifth edition
  Description: Finds percentaje of days below freezing
*/

#include <stdio.h>
#define FREEZING 0

int main (void)
{
  float temperature;
  int cold_days = 0;
  int all_days = 0;

  printf("Enter the list of daily low temperatures.\n");
  printf("Use Celsius and enter q to quit: ");
  
  while (scanf("%f", &temperature) == 1)
  {
    all_days++;
    if (temperature < FREEZING)
       cold_days++;
  }
  if (all_days != 0)
    printf("%d days total: %.1f were below freezing.\n", all_days, (float) cold_days/all_days * 100 );
  if (all_days == 0)
    printf("No data entered!");

  return 0;
}