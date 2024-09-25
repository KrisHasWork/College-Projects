#include <iostream>
using namespace std;
//Code written by Krishan Singh Negi
//Question: Organize n Men and n Women based on their preference so that the pairs are stable.

bool ok(int q[], int newMan) {
int mp[3][3] = {
// q[i]
//  w0 w1 w2      i
    {0, 2, 1}, //m0
    {0, 2, 1}, //m1
    {1, 2, 0}  //m2
};

int wp[3][3] = {
//  m0 m1 m2
    {2, 1, 0}, //w0
    {0, 1, 2}, //w1
    {2, 0, 1}  //w2
};

//Check if the proposed partner is already assigned to another partner
for (int i = 0; i < newMan; i++) {
    if (q[i] == q[newMan]) {
        return false; //Unstable
    }
}

//A: Check if Current Man likes New women more than their current partner! & if 
//B: Check if the newMan likes the Current or previous women more than their current partner
for (int i = 0; i < newMan; i++) {
    if (mp[i][q[newMan]] < mp[i][q[i]] && wp[q[newMan]][i] < wp[q[newMan]][newMan]) { //A
        return false; //Unstable
        }

    if (mp[newMan][q[i]] < mp[newMan][q[newMan]] && wp[q[i]][newMan] < wp[q[i]][i]) { //B
        return false; //Unstable
        } 
    }

return true; //If nothing is unstable ---> it's stable so return trueeeee.
}

//This is just to make printing easier and possibly more efficent?
void print (int q[]) {
cout << "\nMan" << "\t" << "Women";
for (int i = 0; i < 3; i++) {
    cout << endl;
    cout << i << "\t" << q[i];
    }
  cout << endl;
}

//Start of the main program.
int main () {
int q[3];  //"rows"
int c = 0; //Columns
q[c] = 0; //Set the first col to 0 starting off.

//We want to begin a loop after we set one value down. Like 8 queens intilization.
while (c >= 0) { //We end the loop when we get all of the solutions, backtracking c-- means it ends when c = -1;
    c++;

    //When c reaches 3 it means it has gone off the array and we have a solution. So we print.
    if (c == 3) {
        print(q); //Print. 
        c--; //Backtrack.

    //But if it is not currently 3, then it's still looking for a solution. Set q[c] to -1 so it can consider 0 as well.
    } else {
        q[c] = -1;
    }

    //We need a second while loop 
    while (c >= 0) {
        //Controls our "Rows"/Whatever women will be assigned to man c.
        q[c]++;
        if (q[c] == 3) {
            c--;
        } else if (ok(q, c) == true) {
            //If the solution works! Then we want to exit this loop and go back to the previous loop.
            break;
        }
    }

}
return 0;
}