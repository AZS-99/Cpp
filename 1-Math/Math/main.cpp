//
//  main.cpp
//  Math
//
//  Created by Adam Saher on 2021-03-04.
//

#include <iostream>
#include "math.hpp"

int main(int argc, const char * argv[]) {
    std::cout << math::power(10, 0) << std::endl;
    std::cout << math::power(10, 2) << std::endl;
    std::cout << math::approx(12.55, 1) << std::endl;
    std::cout << math::approx(12.545, 2) << std::endl;
    std::cout << math::approx(12.5) << std::endl;
    
    int array[] = {1, 2, 3};
    std::cout << math::sum(array, 3) << std::endl;
    std::cout << math::sqrt(876546888) << std::endl;
    std::cout << math::count_digits(-8900745) << std::endl;
    return 0;
}
