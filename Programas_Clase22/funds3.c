/* funds3.c --- passing a structure as argument */

#include <stdio.h>

#define FUNDLEN 50

struct funds {
   char bank[FUNDLEN];
   double bankfund;
   char save[FUNDLEN];
   double savefund;	
};

double sum (struct funds);

int main (void)
{
  struct funds stan = {
     "Garlic-Melon Bank",
     3024.72,
     "Lucky's Savings and Loan",
     9237.11
  };

  stan.savefund = 2000;
  
  printf("Stan has a total of $%.2f.\n", sum(stan));
  return 0;	
}

/* adds to double numbers */

double sum (struct funds moolah)
{
   return (moolah.bankfund + moolah.savefund);
}
