/* array2d.c --- functions for 2d arrays */

#include <stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows (int ar[][COLS], int rows);
void sum_cols (int [][COLS], int);  // it's okay to omit names
int sum2d (int (* ar) [COLS], int rows);  // another syntax

int main (void)
{
  int junk [ROWS][COLS] = {
	{2,4,6,8},
 	{3,5,7,9},
  	{12,10,8,6}	
  };
  
  sum_rows (junk, ROWS);
  sum_cols (junk, ROWS);
  printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

  getchar();
  
  return 0;	
}

void sum_rows (int ar[][COLS], int rows){ // it works with array notation

  int r, c, tot;
  
  for (r = 0; r < rows; r++){
     tot = 0;
     for (c = 0; c < COLS; c++)
     	tot += ar[r][c];
     printf("Sum of row %d = %d\n", r, tot);
  }
}
	
void sum_cols (int ar [][COLS], int rows)  // it works with array notation
{
    int r, c, tot;
  
    for (c = 0; c < COLS; c++){
      tot = 0;
      for (r = 0; r < rows; r++)
	 tot += ar[r][c];
      printf("Sum of column %d = %d\n", c, tot);
    }
}

int sum2d (int (* ar) [COLS], int rows)  // It works with pointer notation
{
    int r, c, tot;
    for (r = 0, tot = 0; r < rows; r++){
        for (c = 0; c < COLS; c++){
		        tot += *(*(ar + r) + c); //ar == &ar[0] -> ar+r == &ar[r]
            printf("Total = %d\n", tot);

          }
				   	// *(ar+r) == ar[r] == &ar[r][0]
				   	// *(ar+r) + c == &ar[r][c]
					// *(*(ar+r) + c) == &ar[r][c]
    }
    
    return tot;
}
