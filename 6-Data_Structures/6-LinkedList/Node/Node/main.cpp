//
//  main.cpp
//  Node
//
//  Created by Adam Saher on 2021-04-04.
//

#include <iostream>
#include "node.h"

int main(int argc, const char * argv[]) {
    auto node = Node<int>(9);
    node.append(9);
    node.append(9);
    node.append(9);
    node.append(9);
    node.append(9);
    node.append(9);
    
    auto node2 = Node<int>(9);
    node2.append(9);
    node2.append(9);
    node2.append(9);
    
    auto node3 = add_two_numbers(&node, &node2);
    std::cout <<  *node3 << std::endl;
    
    return 0;
}
