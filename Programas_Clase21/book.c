/* book.c --- one book inventory */

#include <stdio.h>
#define MAXTITL 41  //maximum length of title + 1  
#define MAXAUTL 31  //maximum length of author's name + 1 */

struct book {		//structure template: tag is book
  char title[MAXTITL];
  char author[MAXAUTL];
  int code;	
};			//end of structure template

int main (void)
{
  struct book library; //declare library as a book variable.
  
  printf("Please, enter the book title.\n"); 
  gets(library.title); //access to the title member
  printf("Now enter the author.\n");
  gets(library.author);
  printf("Now enter the code.\n"); 
  scanf("%d", &library.code);
  printf("%s by %s\n", library.title, library.author);
  printf("%d\n", library.code);
  printf("Done\n");
  
  getchar();
  getchar();
  return 0;
	
}
