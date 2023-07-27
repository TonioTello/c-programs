/* manybook.c --- multiple book inventory */

#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40  
#define MAXAUTL 30  
#define MAXBKS 100  /* maximum number of books */

struct book {		//structure template: tag is book
  char title[MAXTITL];
  char author[MAXAUTL];
  int code;	
};			//end of structure template

int main (void)
{
  struct book library[MAXBKS]; //array of book structures
  int count = 0;
  int index;
  
  printf("Please, enter the book title.\n"); 
  printf("Press enter at the start of a line to stop.\n");
  while (count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
  {
     printf("Now enter the author.\n");
     gets(library[count].author);
     printf("Now enter the code.\n"); 
     scanf("%d", &library[count++].code); 
     while (getchar() != '\n')
	continue;
     if (count < MAXBKS)
	     printf("Enter the next title.\n");
  }
  if (count > 0)
  {
    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++){
	printf("%s by %s\n", library[index].title, library[index].author);
	printf("%d\n", library[index].code);
    }
  }
  else
    printf("No books? Too bad.\n");
    system ("pause");

    getchar();
  return 0;
}
