#include <iostream>
using namespace std;
//Program written by Krishan Singh Negi in VS Studiocode.
//Question Index: 8 Queens Dumb Method and Forloops.

bool ok (int q[]) {
  //We are given a completed array. We need to test each part of it. Start at 7 and compare it too all parts of the array.
  for(int c = 7; c >= 0; c--) {
    for (int j = 0; j < c; j++) {

  //Upper Diagonal Test and row test
    if((c - j) == abs(q[c] - q[j]) || q[j] == q[c]) {
      return false;
    }
  }
}
return true;
}

int main () {
int sol_set = 1;
int q[8];
//Each for loop is meant too simulate one variable in the array and 1 Column on the chessboard.
for (int i0 = 0; i0 < 8; i0++) {
    for (int i1 = 0; i1 < 8; i1++) {
        for (int i2 = 0; i2 < 8; i2++) {
            for (int i3 = 0; i3 < 8; i3++) {
                for (int i4 = 0; i4 < 8; i4++) {
                    for (int i5 = 0; i5 < 8; i5++) {
                        for (int i6 = 0; i6 < 8; i6++) {
                            for (int i7 = 0; i7 < 8; i7++) {
                             //Will go through all of the possible values. We need a way to filter through and find the right ones.
                             q[0] = i0;
                             q[1] = i1;
                             q[2] = i2;
                             q[3] = i3;
                             q[4] = i4;
                             q[5] = i5;
                             q[6] = i6;
                             q[7] = i7;
                         
                         
                             if (ok(q) == true) {
                              cout << "\nSolution #" << sol_set++ << ": ";
                              for (int p = 0; p < 8; p++) {
                                cout << q[p] << ", ";
                              } 
                              cout << "\n";
                            
                             //rows
                             for (int i = 0; i < 8; i++) { // Print
                              //Columns
                              for(int j = 0; j < 8; j++) {
                                if (q[j] == i) {
                                  cout << "1" << " ";
                                } else {
                                  cout << "0" << " ";
                                }
                              }
                              cout << "\n";
                              }
                              }
                            }
                        }
                    }
                }
            }
        }
    }
}
return 0;
}