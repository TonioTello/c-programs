/* hotel.h --- constants and declarations for hotel.c */

#define QUIT 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define DISCOUNT 0.95
#define STARS "*************************"

// show list of choices
int menu (void);
//returns numbers of nigths desired
int getnights (void);

/*prints the total price for staying in a particular hotel
the first parameter is the rate according to the hotel and
the second parameter is the number of nigths
*/
void showprice(double rate, int nights);

