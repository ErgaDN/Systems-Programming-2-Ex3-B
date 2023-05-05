/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;



int main() {
    // Fraction a(5,3), b(14,21);
    // cout << "a: " << a << "b: " << b << endl;
    // cout << "a+b" << a+b << endl; 
    // cout << "a-b" << a-b << endl; 
    // cout << "a/b" << a/b << endl; 
    // cout << "a*b" << a*b << endl; 
    // cout << "2.3*b" << 2.3*b << endl; 
    // cout << "a+2.421" << a+2.421 << endl; 
    // Fraction c = a+b-1;
    // cout << c++ << endl;
    // cout << --c << endl;

    // cout << "c >=b ? : " << (c >= b) << endl;
    // if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    // else cout << " a is smaller than 1.1" << endl;

    // Fraction f(0.001), k(9,5), o(0.0),  m(2147483647, 1);
    // long x = 2147483647;
    // cout << "x = " << x << endl;
    // Fraction a(0,1), b(0,-3);
    // // a = a/0;
    // cout << a << endl;
    // cout << b << endl;
    // if(a == b)
    //     cout << "hello" << endl;
    // cout << "Fraction() = " << Fraction() << endl;
    // cout << "Fraction(0.0) = " << Fraction(0.0) << endl;
    // cout << "Fraction(2.12345) = " << Fraction(2.12345) << endl;
    // cout << "Fraction(9,5) = " << Fraction(9,5) << endl;
    // cout << "Fraction(f) = " << Fraction(INT_MAX + 3, 1) << endl;
    // cout << "Fraction()" << Fraction() << endl;
    
    // ostringstream os;

    // Test operator<<
    // (os << a); // Not thrwoing error

    // istringstream is("5 6"); // Could also be "5,6" for ex
    // istringstream bad_is("7");
     int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    Fraction f1(max_int, 1);
    Fraction f4(max_int - 100, max_int);
    cout << "f1 = " << f1 << endl;
    cout << "f4 = " << f4 << endl;
    // Test operator>>
    // (bad_is >> b);
    Fraction a = f1 * f4;
    cout << "f1*f4 = " << a << endl;
    // cout << "b = " << b << endl;
    // std::stringstream ss_in("1 2 3 -4");
    // Fraction frac1, frac2;
    // ss_in >> frac1 >> frac2;
    
    // cout << (frac1, Fraction{1, 2}) << endl;
    // cout << (frac2, Fraction{3, -4}) << endl;

    // std::stringstream ss_out;
    // ss_out << frac1 << " and " << frac2;

    long l = (long)(max_int) * (long)(max_int);
    cout << "l   = " << l << endl;
    cout << "l+1 = " << l*1000000000 << endl;
    

    

    


}
