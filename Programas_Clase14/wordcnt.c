/* wordcnt.c --- counts characters, words and lines */

#include <stdio.h>
#include <ctype.h>  // for isspace()

#define STOP '|'

int main (void)
{
  char c; 	// read in character
  char prev; 	// previous character read
  long n_chars = 0L;	// number of characters
  int n_lines = 0;	// number of lines
  int n_words = 0;	// number of words
  int p_lines = 0;	// number of partial lines
  int inword = 0;	// == true if c is in a word

  printf("Enter text to be analyzed (| to terminate) : \n");
  prev = '\n';   // used to identify complete lines
  while ((c = getchar()) != STOP)
  {
    n_chars++;	// count characters
    if (c == '\n')
	n_lines++; // count lines
    if (!isspace(c) && !inword)
    {
      inword = 1;  // starting a new word
      n_words++;
    }	    
    
    if (isspace(c) && inword)
      inword = 0;  // reached end of the word
      
    prev = c;  // save character value
  }
  
  if (prev != '\n')
    p_lines = 1;

  printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
  
  printf("partial lines = %d\n", p_lines);

  return 0;

}






