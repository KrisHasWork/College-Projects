#include <iostream>
using namespace std;

bool okay (int q[], int c) { /*Function to check if 
the current placement of the new proposed queen is fine.*/
    for (int i = 0; i < c; i++) {
        //Two checks in one, 1. Checks if Queen is on the same row as another Queen, 2. Checks diagonally down and up!
        if ((q[c] == q[i]) || (c - i) == abs(q[c] - q[i])) {
            return false;
        }
    }
//If there is no queen diagonally or vertically on the same path as the proposed queen, return true!
return true;
}

int n_queens_solution (int n) {
  int* q_board = new int[n]; //Amount of nXn and amount of queens we try to place.
  int solution_amount = 0; //What we will return.
  int c = 0; //Column
  q_board[c] = 0; //Place first Queen on row 0 and column 0

  while (c >= 0) {
    c++;
    if (c > n - 1) {// n - 1, 8 Queens we check if c > 8 - 1 ---> c > 7.
        solution_amount++; //Every time we find a solution ---> we count it.
    } else {
        q_board[c] = -1; //Set "row" to -1 so that it can start at 0.
    }

    while (c >= 0) {
      q_board[c]++; //How we move from row to row.
      if (q_board[c] > n - 1) {//Our backtrack!
        c--;
      } else if (okay(q_board, c)) {//We call in our check, if it the value is okay we break the loop.
        break;
    }
    }
  }
    delete [] q_board; //Dealocate the memeory we allocated at the beginning.
    return solution_amount; //Return the amount of solutions.
}

int main () {
  int n; //Number user will use to store values.
  cout << "Queens amount?: "; 
  cin >> n;

  //print out the amount of solutions through calling the function.
  for (int i = 1; i < n + 1; ++i) {
    cout << "There are " << n_queens_solution(i) << " solutions to the " << i << " queens problem." << endl;
  }
return 0;
}