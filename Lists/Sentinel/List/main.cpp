//
//  main.cpp
//  Sentinel
//
//  Created by Adam Saher on 31/01/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "List.hpp"
int main(int argc, const char * argv[]) {
    List<int> s;
    
    s.push_back(10);
    s.push_back(20);
    std::cout << s << std::endl;
    
    for (auto it = s.cbegin(); it != s.cend() ; ++it)
        std::cout << *it << ", ";
    
    
}
