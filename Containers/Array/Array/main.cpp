//
//  main.cpp
//  Array
//
//  Created by Adam Saher on 17/12/2018.
//  Copyright © 2018 Adam Saher. All rights reserved.
//


#include <array>
#include <vector>
#include "Array.h"

int main(int argc, const char * argv[]) {
    Array<int, 5> a1;
    std::cout << a1;
    
    Array<int, 10> a = {1, 3, 4};
    std::cout << a << std::endl;
    Array<int, 4> b;
    
    Array<int, 5> a5 = {1, 2};
    auto a6 = a5;
    for (auto& element : a6)
        std::cout << "a6: " << element << ' ';
    
    a1 = a5;
    
    std::vector<Array<int, 10>> vec(10);
    vec.push_back(Array<int, 10>({1, 2}));
    
    return 0;
}

