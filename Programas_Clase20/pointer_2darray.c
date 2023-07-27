/* pointer_2darray.c --- This program shows several errors using pointers and multidimensional arrays */

#include <stdio.h>

int main (void)
{
int matrix[2][3] = {{1,3,7}, {4,5,6}};
int * ptd; // pointer to int
int ** ptp;  // pointer to pointer to int
int (* ptm)[3]; // pointer to an array of 3 ints


/* matrix == &matrix[0] == the address of an array of 3 ints */
ptp = matrix; //wrong 
ptd = matrix; //wrong
ptm = matrix; //right

printf("ptd = %p, ptm = %p\n", ptd, ptm);
printf("*ptd = %d, *ptm = %d\n", *ptd, *ptm);
printf("*ptd+1 = %d, *ptm+1 = %d\n", *ptd+1, *ptm+1);
printf("*(ptd+1) = %d, *(ptm+1) = %d\n", *(ptd+1), *(ptm+1));
printf("ptd[1] = %d, ptm[1][2] = %d\n", ptd[1], ptm[1][2]);
printf("*matrix = %d, *(*(matrix)) = %d\n", *matrix, *(*(matrix)));
printf("ptp = %p, matrix = %p\n", ptp, matrix);
printf("*ptp = %p, *matrix = %p\n", *ptp, *matrix);
// **ptp = 2;

return 0;
}
