/* friends.c -- uses pointer to a structure */

#include <stdio.h>

#define LEN 20


struct names {		//first structure
	char first[LEN];
	char last[LEN];
};

struct guy {		//second structure
	struct names handle; //nested structure
	char favfood[LEN];    //favorite food
	char job[LEN];
	float income;
};

int main (void)
{
  struct guy fellow[2] = {
      {{"Jack","Sparrow"},
       "salmon",
       "pirate",
       38943247.8949
      },
      {{"Forrest", "Gump"},
       "shellfish",
       "runner",
       89324792749.8 
      }
  };
  
  struct guy * him; // him is a pointer to structure
  
  printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
  him = &fellow[0];
  printf("pointer #1: %p #2: %p\n", him, him + 1);
  printf("him -> income is $%.2f, (*him).income is $%.2f\n", him -> income, (*him).income);
  him++;	//point to the next structure
  printf("him -> favfood is %s, him -> handle.last is %s\n", him -> favfood, him -> handle.last);

  getchar();
  return 0;
  	
}