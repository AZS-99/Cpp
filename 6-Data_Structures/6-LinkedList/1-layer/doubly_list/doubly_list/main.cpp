//
//  main.cpp
//  doubly_list
//
//  Created by Adam Saher on 2021-04-29.
//

#include <iostream>
#include "node.h"

int main(int argc, const char * argv[]) {
    auto node = Node<int>(10);
    node.append(11);
    node.append(12);
    std::cout << node << std::endl;
    
    auto node2 = std::move(node);
    node2.next->next->value = 20;
    std::cout << node2 << std::endl;
    std::cout << node << std::endl;
    std::cout << *(node2.next->prev) << std::endl;
    return 0;
}
