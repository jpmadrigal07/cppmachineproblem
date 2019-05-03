#include <iostream>
using namespace std;

// 2 dimensional array sizes
const int numrows = 5;
const int numcols = 7;
// count of reserved seats
int reservedcount = 0;
// user input for seat
int seatnumber;
// activate functions for runtime calling
void populate (int seats[numrows][numcols], int array[]);
void printseats (int seats[numrows][numcols], int array[]);

int main() {