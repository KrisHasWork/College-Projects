#include <iostream>
using namespace std;
int main () {
  //Code written by Krishan Singh Negi in VS Studio Code
  //24 Feburary, 2024. 1 day before it's due.
  //Question Index: 8 Queens Problem with a 2d array, backtracking and  Goto 

  //Initalization
  int sol_numb = 1; 
  int cb[8][8];
  
  //Sets every number in cb array to 0.
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        cb[i][j] = 0;
    }
  }

  //Place the first queen on 0, 0
  int r = 0, c = 0;
  cb[r][c] = 1;
 
  //New Column
nc: 
  c++;
  if (c == 8) {
    goto print;
  }
  r = -1;

  //New Row
nr: 
  r++;
  if (r == 8) {
    goto backtrack;
  }

  //Tests
  //Row test
  for (int i = 0; i <= c; i++) {
    if (cb[r][c - i] == 1) {
      goto nr;
    }
  }

  //upward Diagonal Test to the left
  for (int i = 0; (r - i) >= 0 && (c - i) >= 0; i++) {
    if (cb[r - i][c - i] == 1) {
      goto nr; 
    }
  }

  //downard Diagonal test to the left
  for (int i = 0; (r + i) <= 7 && (c - i) >= 0; i++) {
    if (cb[r + i][c - i] == 1) {
      goto nr;
    }
  }

  //If all the checks pass then place a queen!
  cb[r][c] = 1;

  //Then go to next col and DO IT ALLLL OVER AGAIN!!!!
  goto nc;

  //Print
print:
  cout << "\nSolution #" << sol_numb++ << ": " << "\n";
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 7; j++) {
        cout << cb[i][j] << " ";
    }
    cout << endl;
  }

backtrack:
  //We want to find the last queen that was placed and remove it!
  c--;
  if (c < 0) {
    return 0;
  }
  //Start at the top of the col
  r = 0;
  
  //We want to move down the col to check for a queen now.
  for (int i = 0; i < 8; i++) {
    if (cb[r + i][c] == 1) {
      //Remove Queen
      cb[r + i][c] = 0;

      //We want to start one row AFTER the row we just removed the queen.
      r = r + i;
      goto nr;
    }
  }
}