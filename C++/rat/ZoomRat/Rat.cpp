#include <iostream>
using namespace std;

class Rat { // this is a fraction

// private means only accessable within the class

private: // member variables
	int n; // numerator
	int d; // denominator

public:
// constructors
// default constructor

	// constructor name is same as class name
	Rat(){
		n=0;
		d=1;
	}
// 2 parameter constructor
	Rat(int i, int j){
		n=i;
		d=j;
	}

// conversion constructor
	Rat(int i){
		n=i;
		d=1;
	}
//accessor functions (usually called get() and set(...) )
	int getN(){ 
		return n;
	}
	int getD(){ 
		return d;
	}
	void setN(int i){ 
		n=i;
	}
	void setD(int i){ 
		if(i != 0)
			d=i;
	}

//arithmetic operators
	Rat operator+(Rat r){ // this is called when you add rat with rat
		Rat temp; // 0/1
		temp.n = n * r.d + d * r.n; // setting the num of t
		temp.d = d * r.d;           // setting the denom of t
		return temp;
	}

	Rat operator-(Rat r){ // this is called when you add rat with rat
		Rat temp; // 0/1
		if (r.d == d) {
		temp.n = n + r.n;
		temp.d = d;
		} else {
		temp.n = n * r.d - d * r.n; // setting the num of t
		temp.d = d * r.d;           // setting the denom of t
		}
		return temp;
	}

	void reduce() {
		// reduces the fraction to lowest terms
		// <INSERT CODE HERE>
	}

// 2 overloaded i/o operators
	friend ostream& operator<<(ostream& os, Rat r);
	friend istream& operator>>(istream& is, Rat& r);
}; //end Rat
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
	os<<r.n<<" / "<<r.d<<endl;
	return os;}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
	istream& operator>>(istream& is, Rat& r){
		is>>r.n>>r.d;
		return is;
	}