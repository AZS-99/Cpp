//
//  main.cpp
//  Sentinel
//
//  Created by Adam Saher on 31/01/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Sentinel.h"
int main(int argc, const char * argv[]) {
    Sentinel<int> s;
    try {
        s.pop_front();
    }
    catch (std::string& error) {
        std::cout << error << std::endl;
    }
    
}
