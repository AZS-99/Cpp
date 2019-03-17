//
//  main.cpp
//  Sentinel
//
//  Created by Adam Saher on 31/01/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "List.hpp"
#include <list>


int main(int argc, const char * argv[]) {
    List<std::string> s;
    
    s.push_back("Adam");
    s.push_back("Zack");
    s.push_back("Saher");
    std::cout << s << std::endl;
    auto it = s.cbegin();
    auto it2 = s.cbegin();
    for (; it != s.cend() ; it2 = it++)
        std::cout << *it << ", ";
    std::cout << "Now: " << *it << std::endl;
    ++it;
    std::cout << "Now: " << *it << std::endl;
    
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    std::cout << "end: " << *(--l.cend()) << std::endl;
    
    
}
