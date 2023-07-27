/* exercise1.c : It is a program with several errors

Author: Carlos H. Mendoza C. <carlosmendoza@ieee.org>
Usage: Found and correct the errors!

Rev. History: v1.0 06/07/2009

*/

#include <stdio.h>

#define B pena
#define X = 10

main (int)
{
  int age;
  char name;
  
  printf("Por favor, ingrese su nombre: ");
  scanf("%s", name);
  printf("Hola %c, cuál es su edad?: ", name);
  scanf("%f", age);
  xp = age + X;
  printf("Es una %s!, debes tener al menos %d. \n", B, xp);

  return 0;

}