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
    std::cout << sum(10) << std::endl;
    std::cout << sum(90, 100) << std::endl;
    size_t array[] = {1, 2, 3};
    std::cout << sum(array, 3) << std::endl;
    std::cout << number_of_digits(505) << std::endl;
    
    auto array1 = split(654943);
    for (auto i = 0u; i < 6; ++i)
        std::cout << array1[i] << ' ';
    std::cout << std::endl;
    return 0;
}
