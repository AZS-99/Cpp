//
//  main.cpp
//  2-Fraction
//
//  Created by Adam Saher on 2021-03-08.
//

#include <iostream>
#include "fraction.hpp"

int main(int argc, const char * argv[]) {
    auto fraction1 = Fraction(18, 12);
    auto fraction2 = Fraction(17, 9);
    fraction1 -= fraction2;
    
    std::cout << fraction1 << std::endl;
    
    
    return 0;
}
