#include <iostream>
using namespace std;
int main () {
int c = 0;
int q[8];
q[c] = 0;

int helper[8][8] = {
    {-1}, 
    {0, -1},
    {0, -1},
    {0, 1, 2, -1},
    {0, 1, 3, -1},
    {1, 4, -1},
    {2, 3, 4, -1},
    {3, 4, 5, 6, -1}
};


//col
col:
c++;
if (c == 8) {
    goto print;
}
q[c] = -1;

//rows
row:
q[c]++;

//Do some checks.
if (q[c] >= 8) {
    goto backtrack;
}

for (int i = 0; i < c; i++) {
    
}

//backtrack
backtrack:
c--;
if (c <= -1) {
    return 0;
}
goto row;


//print
print:
cout << endl;
for (int i = 0; i < 9; i++) {
    cout << q[i] << " ";
}
goto backtrack;

}