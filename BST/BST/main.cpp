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
    BST<int> b;
    b.insert(10);
    b.insert(1);
    b.insert(20);
    b.insert(30);
    b.insert(2);
    b.insert(4);
    b.insert(25);
    
    b.in_order(std::cout);
    
    return 0;
}
