//
//  Fraction.cpp
//  Fraction
//
//  Created by Laura Zhang on 9/16/22.
//

#include "Fraction.hpp"

#include <numeric>

Fraction::Fraction() {
    _numerator = 0;
    _denominator = 1;
    _real_representation = 0.0;
    _gcd = 1;
    _lcm = 1;
}

Fraction::Fraction(const int numerator, const int denominator) {
    assert((_denominator != 0) && "The denominator should not be 0!");
    
    _gcd = std::gcd(_numerator, _denominator);
    
    _numerator = numerator / _gcd;
    _denominator = denominator / _gcd;
    
    _real_representation = numerator * 1.0 / denominator;
    
    _lcm = std::lcm(_numerator, _denominator);
}

// copy constructor
Fraction::Fraction(const Fraction& f) {
    _numerator = f._numerator;
    _denominator = f._denominator;
    _real_representation = f._real_representation;
    _gcd = f._gcd;
    _lcm = f._lcm;
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
    if (_denominator == rhs._denominator) {
        _numerator += rhs._numerator;
    }
    
    else {
        _numerator = _numerator * rhs._denominator + _denominator * rhs._numerator;
        _denominator *= rhs._denominator;
    }
    
    _gcd = computeGCD(_numerator, _denominator);
    
    return * this;
}

int Fraction::computeGCD(int& num, int& denom) {
    _gcd = std::gcd(num, denom);
    
    _numerator = num / _gcd;
    _denominator = denom / _gcd;
}

