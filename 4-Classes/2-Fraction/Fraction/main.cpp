//
//  main.cpp
//  2-Fraction
//
//  Created by Adam Saher on 2021-03-08.
//

#include <iostream>
#include "fraction.hpp"

int main(int argc, const char * argv[]) {
    auto f1 = Fraction(1, 2);
    auto f2 = Fraction(2, 3);
    std::cout << (f1 < f2) << std::endl;
    f1 -= f2;
    
    std::cout << f1 << std::endl;
    
    
    return 0;
}
