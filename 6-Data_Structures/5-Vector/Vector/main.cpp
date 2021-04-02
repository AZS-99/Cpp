//
//  main.cpp
//  Vector
//
//  Created by Adam Saher on 2021-03-25.
//

#include <iostream>
#include <vector>
#include "vector.h"

int main(int argc, const char * argv[]) {
    Vector<int> vec = Vector<int>(10);
    vec.push_back(11);
    vec.back() = 12;
    auto vec2 = vec;
    
    
    std::cout << "capacity: " << vec2.capacity() << std::endl;
    
    vec2.shrink_to_fit();
    vec2.print(std::cout);
    std::cout << "New Capacity: " << vec2.capacity() << std::endl;
    
    auto std_vec = std::vector<int>(10);
    std_vec.front() = 44;
    std_vec.insert(std_vec.begin(), 9);
    std::cout << std_vec.front() << std::endl;
    
    auto ptr = std_vec.data();
    *ptr = 10;
    
    std_vec.clear();
    std::cout << "After clear: " << std_vec.capacity() << std::endl;
    for (auto it = std_vec.cbegin(); it < std_vec.end(); ++it)
        std::cout << "this" << *it << ", ";
    std::cout << std::endl;
    
    
    return 0;
}
