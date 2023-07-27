/*reallocating.c -- it shows the use of realloc() */

#include <stdio.h>
#include <stdlib.h> /* for calloc(), realloc() and free() */

int main (void)
{
  int * ptr;
  int i;
  
  ptr = calloc(5, sizeof(int));
  if (ptr != NULL) {
    *ptr = 1;
    *(ptr + 1) = 2;
    ptr[2] = 4;
    ptr[3] = 8;
    ptr[4] = 16;
    //ptr[5] = 32; This will be an error
    ptr = realloc(ptr, 7 * sizeof(int));
    if (ptr != NULL){
	printf("Now allocating more memory...\n");
	ptr[5] = 32; // Now it is legal!
	ptr[6] = 64;
	for (i = 0; i < 7; i++)
	   printf("ptr[%d] holds %d\n", i, ptr[i]);
	free(ptr);
	return 0;
    }
    else {
	    printf("Not enough memory --- realloc failed.\n");
	    return 1;
    }
  }
  else {
	  printf("Not enough memory --- calloc failed.\n");
	  return 1;
  }
}
  
	