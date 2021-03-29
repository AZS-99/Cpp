//
//  fraction.hpp
//  2-Fraction
//
//  Created by Adam Saher on 2021-03-08.
//

#ifndef fraction_hpp
#define fraction_hpp

class Fraction {
    unsigned numerator;
    unsigned denominator;
    bool is_positive;
    
public:
    Fraction(const int&, const int&);
    bool operator==(const Fraction&) const; //The trailing 'const' means the method can't modify the instance *this
    bool operator!=(const Fraction&) const;
    bool operator<(const Fraction&) const;
    bool operator>(const Fraction&) const;
    Fraction operator+(const Fraction&) const;
    Fraction operator-(const Fraction&) const;
    Fraction operator*(const Fraction&) const;
    Fraction operator/(const Fraction&) const;
    void operator+=(const Fraction&);
    void operator-=(const Fraction&);
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
};

#endif /* fraction_hpp */
