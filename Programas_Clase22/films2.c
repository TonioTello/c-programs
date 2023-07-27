/* films2.c --- using a linked list of structures */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // has the strcpy prototype
#define TSIZE 45  //size of array to hold title

struct film {
  char title[TSIZE];
  int rating;
  struct film * next; //points to the next structure in the list
};

int main (void)
{
  struct film * head = NULL;
  struct film * prev, * current; 
  char input[TSIZE];
  
  /* Gather and store information */
  puts("Enter first movie title: ");
  while(gets(input) != NULL && input[0] != '\0')
  {
     current = (struct film *)malloc(sizeof(struct film));
     if (head == NULL)  /* first structure */
	head = current;
     else
	prev->next = current;
     current->next = NULL;
     strcpy(current->title, input);
     puts("Enter your rating (0-10): ");
     scanf("%d", &current->rating);
     while(getchar() != '\n')
	     continue;
     puts("Enter next movie title (empty line to stop): ");
     prev = current;
  }
  
  /* show list of movies */
  if (head == NULL)
	puts("No data entered");
  else
	puts("Here is the movie list: \n");
  current = head;
  while (current != NULL){
      printf("Movie: %s Rating: %d\n", current->title, current->rating);
      current = current->next;
  }
  
  /*program done, so free allocated memory */
  current = head;
  while(current != NULL)
  {
    free(current);
    current = current->next;
  }
  printf("Bye.\n");
  
  return 0;
}
