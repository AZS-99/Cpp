//
//  cstring.cpp
//  1-cstring
//
//  Created by Adam Saher on 2021-03-16.
//

#include "cstring.hpp"

namespace cstring {
    unsigned strlen(const char* chars) {
        return !chars[0]? 0u : strlen(chars + 1) + 1u;
    }

    //remember that pointers are copied when passed as arguments.
    //const pointer means it can't change the values of what it points to, but the pointer itself can move.
    char* dynstrcpy(char*& destination, const char* src) {
        delete[] destination; //PROBLEM IF DANGLING (REVIEW) 
        destination = new char[strlen(src)];
        auto tmp = destination;
        while(*src)
            *destination++ = *src++;
        return destination = tmp;
    }
}
