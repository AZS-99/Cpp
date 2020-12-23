//
//  main.cpp
//  String
//
//  Created by Adam Saher on 05/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <vector>
#include <string>
#include "String.hpp"

int main(int argc, const char * argv[]) {
    
    String str("louis");
    std::cout << str << std::endl;
    
    String str2 = String("Adam");
    std::cout << str << std::endl;
    
    String str3(String("Nader"));
    std::cout << str2 << std::endl;
    
    std::vector<String> vec(10);
    vec.push_back(String("Tariq"));
    
    str[2] = 'f';
    std::cout << str << std::endl;
    return 0;
}
