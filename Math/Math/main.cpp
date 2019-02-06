//
//  main.cpp
//  Math
//
//  Created by Adam Saher on 01/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Math.hpp"

int main(int argc, const char * argv[]) {
    std::cout << math::sum(10) << std::endl;
    std::cout << math::sum(90, 100) << std::endl;
    size_t array[] = {1, 2, 3};
    std::cout << math::sum(array, 3) << std::endl;
    std::cout << math::number_of_digits(505) << std::endl;
    
    auto array1 = math::split(654943);
    for (auto i = 0u; i < 6; ++i)
        std::cout << array1[i] << ' ';
    std::cout << std::endl;
    
    std::cout << math::pow(10, 2) << std::endl;
    std::cout << math::approximate(10.5) << std::endl;
    std::cout << math::approximate(20.4561, 3) << std::endl;
    std::cout << math::floor(12.4) << std::endl;
    std::cout << "sqrt = " << math::sqrt(100000000) << std::endl;
    
    return 0;
}
