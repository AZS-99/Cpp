//
//  Recursion.cpp
//  Recursion
//
//  Created by Adam Saher on 27/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//
#include <cstring>
#include "Recursion.hpp"
bool isPalindrome (const char* str) {
    if (strlen(str) < 2)
    return true;
    char* str2 = new char[strlen(str) - 1];
    strncpy(str2, str + 1, strlen(str) - 2);
    return isPalindrome(str2) && (str[0] == str[strlen(str) - 1]);
}


unsigned summation(unsigned n) {
    if (n < 2)
    return n;
    return summation(n - 1) + n;
    
}


unsigned sum_of_digits(unsigned n) {
    if (n < 10)
    return n;
    return sum_of_digits(n/10) + sum_of_digits(n % 10);
    
}
