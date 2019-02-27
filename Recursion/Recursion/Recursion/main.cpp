//
//  main.cpp
//  Recursion
//
//  Created by Adam Saher on 20/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>

#include "Recursion.hpp"


int main(int argc, const char * argv[]) {
    char* n = new char[5];
    strcpy(n, "noon");
    std::cout << (isPalindrome(n)? true : false) << std::endl;
    std::cout << summation(10) << std::endl;
    std::cout << sum_of_digits(1234) << std::endl;
    
    return 0;
}
