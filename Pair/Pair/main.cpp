//
//  main.cpp
//  Pair
//
//  Created by Adam Saher on 17/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Pair.h"

int main(int argc, const char * argv[]) {
    auto p = make_pair(10, std::string("hi"));
    
    auto p2 = std::make_pair(10, 20);
    std::cout << p2.first << std::endl;
    p2.first = 30;
    std::cout << p2.first;
}
