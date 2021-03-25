//
//  main.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#include <iostream>
#include <cstring>
#include "string.hpp"

int main(int argc, const char * argv[]) {
    auto str0 = String("h");                // Regular Constructor
    String str;                             // Empty constructor
    str = String("str1");                   // Constructor then Move Assignment
    String str2;                            // Empty constructor
    str2 = str;                             // Copy assignment


    auto str3 = str;                        // Copy constructor

    str3 = String("str3");                  //Regular Constructor then Move Assignment

    
    
    
    return 0;
}
