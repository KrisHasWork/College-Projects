#include <iostream>
using namespace std;
int main () {
//Inital values.
int q[3];  //Row
int c = 0; //Col
q[c] = 0; //q = {0, ?, ?}

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

//Col
column:
c++; 
if (c == 3) {
    goto print;
}
q[c] = -1;

//"Rows"
row:
q[c]++;

//When do we backtrack? When we reach the last value + 1, we are off the "board".
if (q[c] >= 3) {
    goto backtrack;
}

//Let's do our checks!
for (int i = 0; i < c; i++) {
    if (q[i] == q[c]) {
        goto row;
    }

    if (mp[i][q[c]] < mp[i][q[i]] && wp[q[i]][c] < wp[q[i]][i]) {
        goto row;
    }

    if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) {
        goto row;
    }
    
}
goto column;

//Backtrack
backtrack:
c--;
if (c < 0) {
    return 0;
}
goto row;

//Print

print:
cout << "Men" << "\t" << "Women";
for (int i = 0; i < 3; i++) {
    cout << endl;
    cout << i << "\t" << q[i] << endl;
    
}
cout << endl;
goto backtrack;

}
