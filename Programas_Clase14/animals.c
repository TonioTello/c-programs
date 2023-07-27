/* animals.c --- uses a switch statement */

#include <stdio.h>

int main (void)
{
  char ch;
  
  printf("Give me a letter of the alphabet, and I will give ");
  printf("an animal name\nbeginning with that letter\n");
  printf("Please, type in a letter; type # to end my act.\n");

  while ((ch = getchar()) != '#')
  {
    if ('\n' == ch )
	continue;
    if (islower(ch)) /* lower case only */
	switch (ch)
	{
	  case 'a' : 
		     printf("argali, a wild sheep of Asia\n");
	             break;
	  case 'b' : 
                     printf("babirusa, a wild pig o Malay\n");
		     break;
	  case 'c' : 
                     printf("coati, racoolike mammal\n");
                     break;
          case 'd' : 
		     printf("desman, aquatic, molelike critter\n");
                     break;
	  case 'e' : 
		     printf("echidna, the spiny anteater\n");
                     break;
          case 'f' : 
                     printf("fisher, brownish marten\n");
                     break;
          default  :
                     printf("That's a stumper!\n");
        }  /* end of switch  */
        else 
          printf("I recognize only lower case letters.\n");
        while (getchar() != '\n')
           continue;      /* skip rest of the line */
	printf("Please type another letter or a #.\n");
  }  /* end of outer while */

  printf("Bye\n");

  return 0;

}