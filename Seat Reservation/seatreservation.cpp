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
    
    // variables for the first actual call
    int seats[numrows][numcols];
    int array[35];
    // first actual call
    populate(seats, array);
    printseats(seats, array);

    return 0;
}

// populate the 2 dimensional array
void populate (int seats[numrows][numcols], int array[]) {
    int seatcount = 0;
    for (int rows = 0; rows < numrows; rows++) {
	   for (int cols = 0; cols < numcols; cols++) {
          seatcount++;
          if(reservedcount > 0) {
              for (int arrcols = 0; arrcols < reservedcount; arrcols++) {
                  if(array[arrcols] == seatcount) {
                      seats[rows][cols] = 0;
                  }
              }
              if(seats[rows][cols] != seatcount && seats[rows][cols] != 0) {
                seats[rows][cols] = seatcount;
              }
          } else {
            seats[rows][cols] = seatcount;
          }
	   }
    }
    
    printseats(seats, array);
}

// print the 2 dimensional array
void printseats (int seats[numrows][numcols], int array[]) {
    int seatcount = 0;
    for (int rows = 0; rows < numrows; rows++) {
	   for (int cols = 0; cols < numcols; cols++) {
              cout << " " << seats[rows][cols];
	   }
	   cout << endl;
    }
    
    // user input
    cout << "Enter a seat number to reserve: ";
    cin >> seatnumber;
    
    // invalid number validation
    if(seatnumber < 1 || seatnumber > 35) {
        cout << "\nInvalid seat number\n\n";
        // if invalid reset the 2 dimensional array
        printseats(seats, array);
    }
    
    // taken seats validation
    for (int arrcols = 0; arrcols < reservedcount; arrcols++) {
        if(seatnumber == array[arrcols]) {
            cout << "\nSeat is taken\n\n";
            // if invalid reset the 2 dimensional array
            printseats(seats, array);
        }
    }
    
    // store the user input on the array
    array[reservedcount] = seatnumber;
    
    // add reserved count
    reservedcount++;
    
    // if this is greater than it means that user successfully reserved a seat
    if(reservedcount > 0) {
        cout << "\nSeat successfully reserved\n";
    }
    
    cout << "\n";
    
    // reset the array and repopulate again
    populate(seats, array);
}