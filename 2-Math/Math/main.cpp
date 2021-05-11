//
//  main.cpp
//  Math
//
//  Created by Adam Saher on 2021-03-04.
//

#include <iostream>
#include "math.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << math::approx(12.55, 1) << std::endl;
    std::cout << math::approx(12.545, 2) << std::endl;
    std::cout << math::approx(12.5) << std::endl;
    
    int array[] = {1, 2, 3};
    
    std::cout << math::sqrt(876546888) << std::endl;
    std::cout << "count digits of 8900745: " << math::count_digits(8900745) << std::endl;
    std::cout << math::factorial(4) << std::endl;
    std::cout << math::gcd(2, 3) << std::endl;
    
    double x;
    
    std::cout << "value of x: " << x << std::endl;
    
    std::cout << math::summation(10) << std::endl;
    std::cout << math::sum_digits(234) << std::endl;
    std::cout << "reverse of 12345 is: " << math::reverse(12345) << std::endl;
    

    return 0;
}
