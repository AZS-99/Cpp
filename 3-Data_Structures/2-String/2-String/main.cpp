//
//  main.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#include <iostream>
#include "string.hpp"

int main(int argc, const char * argv[]) {
    auto str = String("hi");
    auto str2 = String(str);
    std::cout << str << std::endl;
    return 0;
}
