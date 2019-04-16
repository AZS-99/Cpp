//
//  main.cpp
//  BST
//
//  Created by Adam Saher on 19/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "BST.h"
int main(int argc, const char * argv[]) {
    
    BST<int> t;
    BST<int> b;
    b.insert(10);
    b.insert(1);
    b.insert(20);
    b.insert(30);
    b.insert(18);
    b.insert(2);
    b.insert(0);
    b.insert(4);
    b.insert(25);
    b.insert(19);
    
    std::cout << b << std::endl;
    b.remove(10);
    std::cout << b << std::endl;
    

    auto tmp = b.get_values_between(10, 20);
    
    for (unsigned i = 0; i < b.count_nodes(); ++i)
        std::cout << tmp[i] << " ";
    
    return 0;
}
