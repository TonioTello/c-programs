#include <stdio.h>

#define SIZE 5

int main (void)
{
  int oxen[SIZE] = {5,3,2,8};  /* ok here*/
  int yaks[SIZE];

  //yaks = oxen; 	/* not allowed */
  yaks[SIZE] = oxen[SIZE];  /* invalid */
  //yaks[SIZE] = {5,3,2,8}; /* doesn't work */
  printf("%d\n", yaks[SIZE]);
  return 0;
}