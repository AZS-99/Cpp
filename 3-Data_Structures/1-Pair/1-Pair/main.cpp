//
//  main.cpp
//  1-Pair
//
//  Created by Adam Saher on 2021-03-15.
//

#include <iostream>
#include "pair.hpp"

int main(int argc, const char * argv[]) {
    auto pair = make_pair(10, 11.1);
    auto pair2 = Pair<int, double>();
    pair2.swap(pair);
    
    std::cout << pair.second << std::endl;
    return 0;
}
