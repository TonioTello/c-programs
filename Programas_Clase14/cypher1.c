// cypher1.c --- alter input, preserving space

#include <stdio.h>
#include <stdlib.h>
#define SPACE ' ' //This is quote-space-quote

int main (void)
{
  char ch;
  
  ch = getchar();  // read a character

  while (ch != '\n')   // while not end of line
  {
    if (ch == SPACE)   /* leave the space */
      putchar (ch);    // character unchanged
    else 
      putchar(ch + 1);  // change other characters 
    ch = getchar(); 
  }
  putchar(ch); // prints the newline

  system("pause");
  return 0;

}
