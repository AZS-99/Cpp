//
//  string.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#include <cstring>
#include "string.hpp"


String::String() {
    string = nullptr;
}


String::String(const char* chars) {
    string = new char[std::strlen(chars + 1)];
    std::strcpy(string, chars);
}


std::ostream& String::print(std::ostream& os) const {
    return os << string;
}
