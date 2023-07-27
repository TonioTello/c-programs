/* typesize.c : It is a program to show the size of several basic types

Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>

Usage: Simple execution, no arguments
Rev. History: v1.0. 04/07/2009
*/

#include <stdio.h>

int main (void)
{
   printf("\nThe size of a data of type char is %zd bytes\n", sizeof (char));
   printf("The size of a data of type short is %zd bytes\n", sizeof (short));
   printf("The size of a data of type int is %zd bytes\n", sizeof (int));
   printf("The size of a data of type long is %zd bytes\n", sizeof (long));
   printf("The size of a data of type long long is %zd bytes\n\n", sizeof (long long));
      
   printf("The size of a data of type float is %zd bytes\n", sizeof (float));
   printf("The size of a data of type double is %zd bytes\n\n", sizeof (double));

   return 0;
}