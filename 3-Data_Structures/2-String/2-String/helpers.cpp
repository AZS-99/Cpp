//
//  helpers.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#include "helpers.hpp"

namespace helpers {
    unsigned strlen(const char* chars) {
        return !chars[0]? 0u : strlen(chars + 1) + 1u;
    }


    char* dyn_strcpy (char*& destination, const char* src) {
        delete[] destination; //PROBLEM IF DANGLING, WHICH IS MOSTLY THE CASE (REVIEW) 
        destination = new char[strlen(src)];
        auto tmp = destination;
        while(*src)
            *destination++ = *src++;
        return destination = tmp;
    }
}
