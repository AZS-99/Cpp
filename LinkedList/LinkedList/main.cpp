//
//  main.cpp
//  LinkedListGeneric
//
//  Created by Adam Saher on 11/08/2018.
//  Copyright © 2018 Adam Saher. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"



int main(int argc, const char * argv[]) {
    Container::LinkedList<int> LL;
    LL += 10;
    LL += 11;
    LL += 12;
    std::cout << LL;
}
