#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[8], int c){
  //adjacency matrix
  static int a[8][5] = {
    { -1 }, //0
    { 0, -1}, //1
    { 0, 1, -1}, //2
    { 0, 2, -1 }, //3
    { 1, 2, -1}, //4
    { 1, 2, 3, 4, -1}, //5
    { 2, 3, 5, -1}, //6
    { 4, 5, 6, -1} //7
  };

  //check if the number in position c has already been used
  for(int i = 0; i < c; i++){
    if(q[i] == q[c]) return false;
  }
  //check if numbers are consecutive
  for(int i = 0; a[c][i] != -1; i++) {
    if(abs(q[c]-q[a[c][i]]) == 1) return false;
  }
  return true;
}

//print
void print(int q[8]){
  for (int i = 0; i < 8; i++) {
    cout << q[i] << " ";
  }

   static int solutions = 0;
    cout << "Solution#:" << ++solutions << endl;
    cout << " " << q[1] << q[4] << endl;
    cout << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[6] << endl;
    cout << endl;
}

int main() {
  int q[8] = {}, c = 0;

  while(c >= 0){
    c++;
    if(c == 8) {
      print(q);
      c--;
    } else q[c] = -1;

    while(c>=0) {
      q[c]++;
      if(q[c] == 8) c--;
        else if(ok(q, c)) break;
    }
  }
  return 0;
}