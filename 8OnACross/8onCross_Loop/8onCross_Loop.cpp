#include <iostream>
using namespace std;

bool check (int q[8], int currentCol) {
    //Create helper array that will have all of the values that are next to each other on the cross!
    int helper[8][5] = {
    {-1},               //0
    {0, -1},            //1
    {0, -1},            //2
    {0, 1, 2, -1},      //3
    {0, 1, 3, -1},      //4
    {1, 4, -1},         //5
    {2, 3, 4, -1},      //6
    {3, 4, 5, 6, -1}    //7
};
//We don't check what is not already passed, so 1 does not check 2, only 0.

//Checks
for (int i = 0; i < currentCol; i++) {

    //Check if there is a same number.
    if (q[i] == q[currentCol]) {
        return false;
    }
}
    for (int i = 0; helper[currentCol][i] != -1; i++)
    //Check if whatever they are touching is a difference of 1 based on the helper array. 
    //Helper array defines which boxes we will check.
    if (abs(q[currentCol] - q[helper[currentCol][i]]) == 1) {
        return false;
    }


return true;
}

void print (int q[8],int &sol_number) {
//Print the current solution.
cout << "Solution Set #" << sol_number++ << ": " << q[0];
    for (int i = 1; i < 8; i++) {
        cout << ", " << q[i];
    }
    cout << endl;
    
cout << "  " << q[0] << " " << q[1] << endl;
cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
cout << "  " << q[6] << " " << q[7] << endl; 

}

int main () {
int sol_number = 1;
int c = 0; //Column
int q[8]; //"rows"
q[c] = 1; //Place the first number.

/* Here is how our cross will be structured 
            0   1
        2   3   4   5
            6   7
*/ 

//We want the loop to end and return 0; when we get all of the solutions, we get all the solutions when c < 0.
while (c >= 0) {
    //Move onto the next column.
    c++;

    //Check if 
    if (c >= 8) {
        //When c reaches the end (8) we print and then backtrack.
         print(q, sol_number);
         cout << endl;
         //Backtrack!
         c--;
    } else {
        q[c] = 0;
    }
   
    while (c >= 0) {
        //Increase the current value ---> Then check later on.
        q[c]++;

        //If we somehow go through all of our values and did not find one that works we need to backtrack.
        if (q[c] == 9) {
            //Backtrack!
            c--;

        //Now check if the current values are fine and nothing is being repeated.
        } else if (check(q, c) == true) {
            break;
        }
    }
}

return 0;
}