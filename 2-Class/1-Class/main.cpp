//
//  main.cpp
//  1-Class
//
//  Created by Adam Saher on 2021-03-04.
//

#include <iostream>
#include "circle.hpp"

int main(int argc, const char * argv[]) {
    auto circle = Circle(10);
    std::cout << circle.get_area() << std::endl;
    std::cout << circle.get_circumference() << std::endl;
    return 0;
}
