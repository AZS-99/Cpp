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
    //const pointer doesn't mean it's value can't be changed, but it's dereferenced value can't be.
    char* strcpy(char*& destination, const char* src) {
        delete[] destination;
        unsigned len = strlen(src);
        destination = new char[len];
        for (unsigned i = 0u; i < len; ++i)
            destination[i] = src[i];
        return destination;
    }
}
