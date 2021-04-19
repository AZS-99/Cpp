//
//  main.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#include <iostream>
#include <cstring>
#include "string.hpp"

long long divide(const long long& dividend, const long long& divisor) {
    if (!(dividend < 0) != !(divisor < 0)) {
        return -divide(std::abs(dividend), std::abs(divisor));
    } else {
        if (std::abs(dividend) < std::abs(divisor))
            return 0;
        return divide(std::abs(dividend) - std::abs(divisor), std::abs(divisor)) + 1;
    }
    
}


int main(int argc, const char * argv[]) {
    auto str0 = String("h");                // Regular Constructor
    String str;                             // Empty constructor
    str = String("str1");                   // Constructor then Move Assignment
    String str2;                            // Empty constructor
    str2 = str;                             // Copy assignment

    auto str3 = str;                        // Copy constructor
    
    auto s = String("bacdab");
    std::cout << "palindrome? " << (s.palindrome()? "true" : "false") << std::endl;
    std::cout << std::abs(-10) << std::endl;
    
    std::cout << divide(-2147483648, -1) << std::endl;
    
    
    return 0;
}
