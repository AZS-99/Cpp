//
//  main.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#include <iostream>
#include "iString.hpp"

int main(int argc, const char * argv[]) {
    auto str = String("hi");
    str.print(std::cout);
    return 0;
}
