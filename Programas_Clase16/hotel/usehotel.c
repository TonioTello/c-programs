/* usehotel.c --- room rate program 

Compile with hotel.c
*/

#include <stdio.h>
#include "hotel.h"  // define constants, declare functions

int main (void)
{
  int nights;
  double hotel_rate;
  int code;

  while ((code = menu()) != QUIT)
  {
    switch (code) 
    {
	case 1: hotel_rate = HOTEL1;
		break;
	case 2: hotel_rate = HOTEL2;
		break;
	case 3: hotel_rate = HOTEL3;
		break;
	case 4: hotel_rate = HOTEL4;
		break;
	default: hotel_rate = 0.0;
		 printf("Ooops!\n");
		 break;
    }
    nights = getnights();
    showprice(hotel_rate, nights);
  }
  printf("Thank you and good bye");

  return 0;
}
