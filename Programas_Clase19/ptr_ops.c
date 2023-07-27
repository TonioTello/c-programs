/* ptr_ops.c 
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: pointer operations 
*/

#include <stdio.h>

int main (void)
{
  int urn [5] = {100, 200, 300, 400, 500};
  int * ptr1, * ptr2, * ptr3;
  
  ptr1 = urn;         // assign an address to a pointer
  ptr2 = &urn[2];
  
  printf("\nPointer value, dereferenced pointer, pointer address:\n");
  printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
  printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
  
  // pointer addition
  ptr3 = ptr1 + 4;
  printf("\nAdding an int to a pointer:\n");
  printf("ptr1 = %p, ptr1 + 4 = %p\n", ptr1, ptr3);
  
  // increment a pointer
  ptr1++;
  printf("\nValues after ptr1++:\n");
  printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
  
  // decrement a pointer
  ptr2--;
  printf("\nValues after ptr2--:\n");
  printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
  
  --ptr1; // restore to original value
  ++ptr2; // restore to original value
  printf("\nPointers reset to original values:\n");
  printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
  
  //subtract one pointer from another
  printf("\nSubtracting one pointer from another:\n");
  printf("ptr1 = %p, ptr2 = %p, ptr2 - ptr1 = %d\n", ptr1, ptr2, ptr2 - ptr1);
    
  //subtract an integer from a pointer
  printf("\nSubtracting an int from a pointer:\n");
  printf("ptr3 = %p, ptr3 - 2 = %p\n\n", ptr3, ptr3 - 2);
  
  return 0;
}