//
//  main.cpp
//  1-cstring
//
//  Created by Adam Saher on 2021-03-16.
//

#include <iostream>
#include <cstring>
#include "cstring.hpp"

int main(int argc, const char * argv[]) {
    char* chars = nullptr;
    auto str = cstring::strcpy(chars, "hey");
    std::cout << str << '\t' << chars << std::endl;
    return 0;
}
