//
//  main.cpp
//  BST
//
//  Created by Adam Saher on 2021-04-25.
//

#include <iostream>
#include "BST.h"

int main(int argc, const char * argv[]) {
    auto node = Node<int>(10);
    
    node.insert(7);
    node.insert(15);
    node.insert(8);
    node.insert(1);
    node.insert(2);
    node.insert(12);
    node.insert(16);
    node.insert(14);
    node.insert(11);
    auto [parent, current] = node.find(15);
    std::cout << *current << std::endl;
    return 0;
}
