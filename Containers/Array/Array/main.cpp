//
//  main.cpp
//  Array
//
//  Created by Adam Saher on 17/12/2018.
//  Copyright © 2018 Adam Saher. All rights reserved.
//

#include <iostream>
#include <array>

#include "Array.h"

int main(int argc, const char * argv[]) {
    Container::Array<int, 4> a = {1, 3, 4};
    std::cout << a << std::endl;
    Container::Array<int, 4> b;
    
    std::array<size_t, 5> c = {{1}};
    for (auto& element : c)
        std::cout << element;
    return 0;
}

