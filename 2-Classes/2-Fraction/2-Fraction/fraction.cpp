//
//  fraction.cpp
//  2-Fraction
//
//  Created by Adam Saher on 2021-03-08.
//

#include <iostream>
#include <numeric>
#include "fraction.hpp"

/// <#Description#>
/// @param numerator an int, postitive or negative
/// @param denominator int, positive or negative
Fraction::Fraction(const int& numerator, const int& denominator) {
    int gcd = std::gcd(numerator, denominator);
    this->numerator = std::abs(int(numerator/gcd));
    this->denominator = std::abs(int(denominator/gcd));
    is_positive = numerator < 0? denominator < 0 : denominator > 0;
}


bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator && is_positive == other.is_positive;
}


bool Fraction::operator!=(const Fraction& other) const {
    return !this->operator==(other);
}


Fraction Fraction::operator+(const Fraction& other) const {
    int new_denom = std::lcm(denominator, other.denominator);
    int num =  (new_denom/denominator) * numerator * (is_positive? 1 : -1) + (new_denom/other.denominator) * other.numerator * (other.is_positive? 1 : -1);
    return Fraction(num, new_denom);
}


Fraction Fraction::operator-(const Fraction& other) const {
    int new_denom = std::lcm(denominator, other.denominator);
    int num = (new_denom/denominator) * numerator * (is_positive? 1 : -1) - (new_denom/other.denominator) * other.numerator * (other.is_positive? 1 : -1);
    return Fraction(num, new_denom);
}


Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}


Fraction Fraction::operator/(const Fraction& other) const {
    return *this * Fraction(other.denominator, other.numerator);
}


void Fraction::operator+=(const Fraction& other) {
    auto fraction = *this + other;
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    is_positive = fraction.is_positive;
}


void Fraction::operator-=(const Fraction& other) {
    auto fraction = *this - other;
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    is_positive = fraction.is_positive;
}


std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    return  os << (fraction.is_positive? '+' : '-') << fraction.numerator << '/' << fraction.denominator;
}
