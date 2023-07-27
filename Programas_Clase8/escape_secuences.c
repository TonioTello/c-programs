/* escape_secuences.c : It is a program to show the use of several escape secuences

Author: Carlos H. Mendoza C.

Usage: Simple execution, no arguments
Rev. History: v1.0 04/07/2009

*/

#include <stdio.h>

int main (void)
{
  int dinero;
    
  printf("Atención! \a\a\a\a\a\n");
  printf("Fernando Gonzáles escribió el libro \"Viaje a Pie\"\v");
  printf("Ese libro cuesta $10000...\n");
  printf("Cuánto dinero tiene?: ________\b\b\b\b\b\b\b\b"); 
  scanf("%d", &dinero);
  printf("Usted tiene el %d%% del valor del libro\n", (dinero/10000)*100);

  return 0;  
}
