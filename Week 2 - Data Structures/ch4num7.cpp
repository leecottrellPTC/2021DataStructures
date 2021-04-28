#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main (){
    double a, b, c, root1, root2, disc;

    cout << "Enter a b c from your polynomial ";
    cin >> a >> b >> c;

    cout << "Your polynomial"<< endl;
    cout << a << "x^2 + " << b << "x + " << c << endl;

    disc = b*b - 4*a*c;
    //disc = pow(b, 2) - 4*a*c;

    if(disc == 0){
        root1 = (-b + sqrt(disc)) / 2*a;
        cout << "The one real root is " << root1 << endl;
    }
    else if(disc > 0){
        root1 = (-b + sqrt(disc)) / 2*a;
        root2 = (-b - sqrt(disc)) / 2*a; 
        cout << "The roots are " << root1 << " and " << root2 << endl;
        //cout << "(x + " << root1 << ") and (x + " << root2 << ")" << endl;
    }
    else if(disc < 0){
        cout << "There are no real roots" << endl;
    }
    else {
        cout << "Something really weird happened" << endl;
        return 1;
    }



}