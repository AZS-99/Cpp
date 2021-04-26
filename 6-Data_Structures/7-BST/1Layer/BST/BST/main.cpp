//
//  main.cpp
//  BST
//
//  Created by Adam Saher on 2021-04-25.
//

#include <iostream>
#include "BST.h"

int main(int argc, const char * argv[]) {
    auto node = Node<int>(0);
    node.insert(10);
    node.insert(-10);
    node.insert(9);
    node.insert(11);
    std::cout << node << std::endl;
    return 0;
}
