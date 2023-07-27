/* skippart.c
  Author: Stephan Prata
  Description: uses the statement continue to skip part of the loop 
*/

#include <stdio.h>
#define MIN 0.0
#define MAX 100.0


int main (void)
{
  float score;
  float total = 0.0;
  int n = 0;
  float min = MAX;
  float max = MIN;

  printf ("Print the first score (q to quit)");
  while (scanf("%f", &score) == 1)
  {
    if (score < MIN || score > MAX)
    {
      printf("%.1f is an invalid value. Try again: ", score);
      continue;
    }	
    printf("Accepting %.1f...", score);
    min = (score < min) ? score : min;
    max = (score > max) ? score : max;
    total += score;
    n++;
    printf("Enter next score (q to quit): ");  
  }
  if (n > 0) {
    printf ("Average of %d scores is %.1f.\n", n, total / n);
    printf("Low = %.1f, high = %.1f\n", min, max);
  }
  else 
    printf("No valid scores were entered");
  return 0;
}