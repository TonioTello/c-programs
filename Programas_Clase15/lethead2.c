/* lethead2.c
  Author: Stephan Prata, C Primer Plus, Fifth Edition
  Description: It defines a function that has communication with main()
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/* for strlen */

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int num);  /* prototype the function */ 

int main (void)
{

  int spaces;

  show_n_char('*', WIDTH); // using constants as arguments
  putchar('\n');
  show_n_char(SPACE, 12); // using constants as arguments
  printf("%s\n", NAME);
  spaces = (WIDTH - strlen(ADDRESS)) / 2; // calculate how many spaces to skip
  show_n_char(SPACE, spaces);	// use a variable as argument    
  printf("%s\n", ADDRESS);  
  show_n_char(SPACE, (WIDTH - strlen(ADDRESS)) / 2); // an expression as argument
  printf("%s\n", PLACE);
  show_n_char('*', WIDTH);	/* use the function */
  putchar('\n');
  
  system("pause");
  return 0;

}

/* show_n_char() definition */
void show_n_char (char ch, int num)	/* define the function */
{
  int count;
  
  for (count = 1; count <= num; count++)
	putchar(ch);
}
