//
//  main.cpp
//  HashTable
//
//  Created by Adam Saher on 05/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::hash<std::string> hash_fn_ptr;
    std::string a("hello");
    size_t hash_value = hash_fn_ptr(a);
    std::cout << hash_value << std::endl;
    return 0;
}
