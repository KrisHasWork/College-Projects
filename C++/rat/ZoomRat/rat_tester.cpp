#include <iostream>
#include "Rat.cpp"
using namespace std;

int main() {
Rat x (3, 4), y (3, 4), z;
z = x+y;
cout << z.getN() << "/" << z.getD() << endl;
//z = x-y;
//cout << z.getN() << "/" << z.getD();


}