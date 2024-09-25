#include <iostream>
using namespace std;

int fib (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
return fib(n - 1) + fib(n - 2);
}

int main () {
//int n;
//cout << "Enter a number: "; cin >> n;
cout << "Fib seq from 1 to 100" << endl;

for (int i = 1; i < 101; i++)
cout<< fib(i) << endl;

}