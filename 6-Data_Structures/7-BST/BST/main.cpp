//
//  main.cpp
//  BST
//
//  Created by Adam Saher on 2021-04-11.
//

#include <iostream>
#include "bst.h"

int main(int argc, const char * argv[]) {
    
    
    
    BST<int> bst;
    bst.insert(10);
    bst.insert(7);
    bst.insert(15);
    bst.insert(8);
    bst.insert(1);
    bst.insert(2);
    bst.insert(12);
    bst.insert(16);
    bst.insert(14);
    bst.insert(11);
    std::cout << bst << std::endl;
    bst.remove(12);
    std::cout << bst << std::endl;
    std::cout << "height: " << bst.height() << std::endl;
    
    auto vec = bst.sort();
    for (auto& value : vec)
        std::cout << value << std::endl;
    return 0;
}
