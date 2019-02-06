//
//  main.cpp
//  String
//
//  Created by Adam Saher on 05/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//


#include "String.hpp"

int main(int argc, const char * argv[]) {
    String str;
    std::cout << str << std::endl;
    String str1("String");
    std::cout << str1 << std::endl;
    String str2("Hello");
    str1 = str2;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    String str3("tmp");
    str1 = std::move(str3);
    std::cout << str1 << std::endl;
    std::cout << str3 << std::endl;
    return 0;
}
