#include <iostream>
using namespace std;

//Create the 3 functions
//Line is just x * 1.
double line (double x) {
    return x;
}

//we want to square a number.
double square (double x) {
    return x * x;
}

//We want to cube a number.
double cubed (double x) {
    return x * x * x;
}

//Typedef here is creating a structure 
//The structure POINTS to a function that takes in a double and RETURNS a double. 
typedef double (*func)(double);

/*Main meat of the program.
We create a function that has a pointer function f which points to one of the 3 functions we made above.
a is the starting point of the rectangle and b is the ending point. 
*/
double intergrate(func f, int a, int b) {
    //x will be how we traverse the rectangles. ---> x = x + 0.0001. Each rectangle is only 0.0001 width.
    double x = a;

    //Sum is just our final answer.
    double sum;

    //We want this to end when x = a, exceeds b which is the final point we count.
    while (x < b) {

        //sum = f(x^1 or x^2 or x^3) * Delta 
        //Delta is how LONG a rectangle is (0.0001) and f(x) is the hight of the rectangle. High * Width = Area
        sum += f(x) * 0.0001;
        x = x + 0.0001;
    }
return sum;
}   

int main () {
    //Test for functions.
    /*
    cout << line(2) << endl; 
    cout << square(2) << endl;
    cout << cubed(2) << endl;
    */

    cout << "The integral of f(x) = x between 1 and 5 is: "
    << intergrate(line, 1, 5) << endl;

    cout << "The integral of f(x) = x^2 between 1 and 5 is: "
    << intergrate(square, 1, 5) << endl;

    cout << "The intgral of f(x) = x^3 bewteen 1 and 5 is: "
    << intergrate(cubed, 1, 5) << endl;

}