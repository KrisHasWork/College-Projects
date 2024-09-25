#include <iostream>
using namespace std;

void print (int q[]) {
    //print by checking when q[c] == r
    for (int r = 0; r < 8; r++) { //rows
        for (int c = 0; c < 8; c++) { //columns
          if (q[c] == r) {
            cout << "1" << " ";
          } else {
            cout << "0" << " ";
          }
        }
        cout << endl;
    }
}

bool okay (int q[], int c) {
//Checks for rows
    for (int i = 0; i < c; ++i) {
        if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])) {
            return false;
        }
    }
return true;
}

int main () {
    //Initilalize 
    int q[8];
    int c = 0;
    q[c] = 0;
    int number_counter = 1;

    while (c >= 0) {
        //Move through columns via var c
        c++;

        //Print then backtrack
        if (c > 7) {
            cout << endl;
            cout << "Solution Set #" << number_counter++ << ": ";
            for (int i = 0; i < 8; i++) {
                cout << q[i] << ", ";
            }
            cout << endl;
             print(q);
            c--;
        } else {
            q[c] = -1;
        }

        //Move through Rows via array q[c]
        while (c >= 0) {
            q[c]++;

            if(q[c] > 7) {
                c--;
            } else if (okay(q, c)) {
                break; //break out of the loop and go back to the columns.
            } 
        }
    }
return 0;
}