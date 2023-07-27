/* bounds.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: exceed the bounds of an array
*/

#include <stdio.h>

#define SIZE 4

int main(void)
{
  int value1 = 44;
  int arr[SIZE];
  int value2 = 88;
  int i;

  printf("value1 = %d, value2 = %d, &value1 = %p, &value2 = %p\n", value1, value2, &value1, &value2);
  printf("arr = %p\n", arr);
  for (i = -4444; i <= SIZE + 2242; i++)
    arr[i] = 2 * i + 1;
  for (i = -1; i < 7; i++)
    printf("%2d %d\n", i , arr[i]);
  printf("value1 = %d, value2 = %d\n", value1, value2);
  return 0;
}
