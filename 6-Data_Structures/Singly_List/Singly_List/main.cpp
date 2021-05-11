//
//  main.cpp
//  Singly_List
//
//  Created by Adam Saher on 2021-04-29.
//

#include <iostream>
#include "node.h"

int main(int argc, const char * argv[]) {
    auto node = Node<int>(10);
    node.push_front(11);
    node.push_front(12);
    node.insert_after(16, 33);
    
    auto node2 = node;
    
    node.front() = 0;
    std::cout << node << std::endl;
    return 0;
}
