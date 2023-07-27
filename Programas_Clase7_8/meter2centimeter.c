/* meter2centimeter.c :   It is a simple program to convert meters to centimeters

Author: Carlos H. Mendoza <carlosmendoza@ieee.org>
Usage: Execute without options
Rev. History: v1.0 -  16/06/2009
*/

#include <stdio.h>

int main (void)
{

  int meter, centimeter;
  
  meter = 2;
  centimeter = 100 * meter;

  printf("There is %d centimeters in %d meters\n", centimeter, meter);
  printf("Yes, I say %d centimeters!\n", 100 * meter);

  return 0;

}
  

