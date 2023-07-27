/* string_intro.c : It is a program to introduce the topic of 
                    character string

Author: Carlos H. Mendoza C.

Usage: Input your first name and your height in meters
Rev. History: v1.0 05/07/2009

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CONVERSION 100
#define PHRASE "Brevity is the soul of wit"

int main (void)
{
  char name [20];     //This is a vector to store a character string  

  float meters;
  int centimeters, letters, size;
  
  printf("What is your first name?: ");
  scanf("%s", name);
  printf("Hello %s, what is your height in meters?: ", name);
  scanf("%f", &meters);
  
  letters = strlen(name);
  size = sizeof name;
  centimeters = meters*CONVERSION;

  printf("\nOk, your first name has %d letters and we have %d bytes to store it\n", letters, size);
  printf("Furthermore, you are %d centimeters tall!\n", centimeters);

  printf("\nThe phrase \"%s\" has %d letters and occupy %d bytes in memory\n\n", 
          PHRASE, strlen(PHRASE), sizeof PHRASE);
  system("pause");          
  return 0;
}
