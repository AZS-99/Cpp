//
//  main.cpp
//  String
//
//  Created by Adam Saher on 05/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//


#include "String.hpp"

int main(int argc, const char * argv[]) {
    std::string a = "hello";
    String str;
    std::cout << str << std::endl;
    String str1("String");
    std::cout << str1[2] << std::endl;
    str1.back() = 'G';
    std::cout << str1 << std::endl;
    return 0;
}
