#include <iostream>
using namespace std;

class rat {
private: 
int n; //Numerator
int d; //Denominator

public: //constuctor starts here, we construct our fractions! 

rat () {
    n = 0;
    d = 1;
}

rat (int i, int j) {
    n = i;
    n = j;
}

rat (int i) {
    n = i;
    d = 1;
}


//Accessor functions, so you can manipulate n and d outside the rat class scope.
int getN () {return n;}
int getD () {return d;}

rat operator+ (rat r) {
//add two fractions 
rat answer;
answer.n = n * r.d + d * r.n;
answer.d = d * r.d;
return answer;
}

rat operator- (rat frac) {
rat answer;
answer.n = (n * frac.d) - (frac.n *d);
answer.d = d * frac.d;
return answer;
}

};

int main () {
rat x (1, 2), y (3, 4);
rat z = x+y;
cout << z.getN() << "/" << z.getD() << endl;



return 0;
}