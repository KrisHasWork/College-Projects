#include <iostream>
using namespace std;

/*bool ok (int q[], int c) {
//Tests
  //Row Test
  for(int i = 0; i < c; i++) {
    if (q[i] == q[c]) {
      return false;
    }
  }
  
  //Upper Diagonal Test
  for(int i = 0; i < c; i++) {
    if((c - i) == abs(q[c] - q[i])) {
      return false;
    }
  }
  
return true;
}*/

void print (int q[]) {
  for (int i = 0; i < 9; i++) {
    cout << q[i] << ", ";
  }
}

int main () {
    cout << "INITALIZE" << endl;
    int q[8];
    int c = 0;
    q[0] = 0;
    int count = 0;

    while (c >= 0) {
        c++;
        cout << "current column: " << c << endl; 

        if (c >= 8) {
            cout << "COMPLETE" << endl;
            print(q);
        } 
        
        q[c] = -1;
        
        while (c >= 0) {
            q[c]++;
            cout << "current row: " << q[c] << endl;

            if (q[c] >= 8) {
              c--;
            }

            //Tests
            //Row Test
            for(int i = 0; i < c; i++) {
              if (q[i] == q[c]) {
                q[c]++;
              } 
              
              if (abs((c - i)) == abs(q[c] - q[i])) {
                q[c]++;
              }
            }
        }
    }
return 0;
}