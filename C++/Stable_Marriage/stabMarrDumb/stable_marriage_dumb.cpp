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

return true; //If nothing is unstable ---> it's stable!
}

int main () {
//2, 0, 1 works good test ---> stable
int q[3];  //"rows"
int c = 0; //Columns
int check = 0;

//Run throught every value from 000 to 222 and find the ones that are stable and those that are not.
for (int i0 = 0; i0 < 3; i0++) {
    for (int i1 = 0; i1 < 3; i1++) {
        for (int i2 = 0; i2 < 3; i2++) {
            //Assemble a array.
            q[0] = i0;
            q[1] = i1;
            q[2] = i2;
            check = 0;

            //Test the array!
            for (int i = 0; i < 3; i++) {
                if (ok(q, i) == true){
                    check++; 
                } 
                //Print out the correct answer.
                if(check == 3) {
                    for (int i = 0; i < 3; i++) {
                        cout << q[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

return 0;
}