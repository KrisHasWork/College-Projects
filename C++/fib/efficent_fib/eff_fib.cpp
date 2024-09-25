#include <iostream>
using namespace std;

  int fib (int n) {
  static int memorization[100] = {0};
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } 
  else if (memorization[n] != 0) {
    return memorization[n]; 
  }
  return memorization[n] = fib(n - 1) + fib(n - 2);
} 


int main () {
  
for (int i = 0; i < 100; i++) {
    cout << "Fib #" << i << ": " << fib(i) << endl;
}
  
return 0;
}