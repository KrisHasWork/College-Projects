#include <iostream>
using namespace std;
int main () {
//Code written by Krishan Singh Negi in VS StudioCode
//Question Index: 8 Queens Project 1D Array + Goto + Backtracking.


//queens[r][c]
//Intialization 
int sol_numb = 1;
int queens[8] = {};

//Place first Queen similar as 2D array.
int c = 0;
queens[c] = 0;

//New Column
//Goal: Move onto next col and make sure when going down the rows we can start at the top.
newCol:
  c++;
  if (c == 8) {
    goto print;
  }
  queens[c] = -1;

//New Row

newRow:
  queens[c]++;
  if (queens[c] >= 8) {
    goto backtrack;
  }

  //Tests
  //Row Test
  for(int i = 0; i < c; i++) {
    if (queens[i] == queens[c]) {
      goto newRow;
    }
  }
  
  //Upper Diagonal Test
  for(int i = 0; i < c; i++) {
    if((c - i) == abs(queens[c] - queens[i])) {
      goto newRow;
    }
  }
  
  //Goto onto new column.
  goto newCol;

//Backtrack
backtrack:
 c--;
 if (c == -1) {
   return 0;
 }
goto newRow;

//Print 
print:
cout << "\nSolution Set #" << sol_numb++ << ": ";
 for (int i = 0; i < 8; i++) {
  cout << queens[i] << ", ";
 }
cout << "\n";

//Rows
for (int i = 0; i < 8; i++) {
  //Columns
  for(int j = 0; j < 8; j++) {
   if (queens[j] == i) {
     cout << "1" << " ";
   } else {
     cout << "0" << " ";
   }
  }
 cout << "\n";
}

goto backtrack;
}