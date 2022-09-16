//
//  Fraction.hpp
//  Fraction
//
//  Created by Laura Zhang on 9/16/22.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <iostream>
#include <cmath>

class Fraction {
private:
    int _numerator, _denominator;
    // greatest common divisor
    int _gcd;
    // least common multiple
    int _lcm;
    double _real_representation;
    
    int computeGCD(int& num, int& denom);
    
public:
    Fraction();
    Fraction(const int numerator, const int denominator);
    // copy constructor
    Fraction(const Fraction& f);
    
    // operator
    Fraction& operator=(const Fraction& rhs);
    Fraction operator+(const Fraction& rhs);
    Fraction operator-(const Fraction& rhs);
    Fraction operator*(const Fraction& rhs);
    Fraction operator/(const Fraction& rhs);
    Fraction& operator+=(const Fraction& rhs);
    
    bool operator>(const Fraction& rhs);
    bool operator==(const Fraction& rhs);
    
    Fraction& pow(int exponent) {
        _numerator = std::pow(_numerator, exponent);
        _denominator = std::pow(_denominator, exponent);
        return * this;
    }
    
    Fraction& pow(const Fraction& exponent) {
        _numerator = std::pow(_numerator, exponent._real_representation);
        _denominator = std::pow(_denominator, exponent._real_representation);
        return * this;
    }
    
    
};

std::ostream& operator<<(std::ostream& out, const Fraction f);

#endif /* Fraction_hpp */
