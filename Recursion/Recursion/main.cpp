//
//  main.cpp
//  Recursion
//
//  Created by Adam Saher on 20/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>

bool isPalindrome (const char* str) {
    if (strlen(str) < 2)
        return true;
    char* str2 = new char[strlen(str) - 1];
    strncpy(str2, str + 1, strlen(str) - 2);
    return isPalindrome(str2) && (str[0] == str[strlen(str) - 1]);
}


int main(int argc, const char * argv[]) {
    char* n = new char[5];
    strcpy(n, "noon");
    std::cout << (isPalindrome(n)? true : false) << std::endl;
    return 0;
}
