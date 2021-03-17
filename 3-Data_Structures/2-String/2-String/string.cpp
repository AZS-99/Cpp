//
//  string.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//


#include "string.hpp"
#include "helpers.hpp"


String::String() {
    char_array = nullptr;
}


String::String(const char* chars) {
    helpers::dyn_strcpy(char_array, chars);
}


String::~String() {
    delete[] char_array;
}


String::String(const String& other) {
    helpers::dyn_strcpy(char_array, other.char_array);
}


std::ostream& operator<<(std::ostream& os, const String& string) {
    return os << string.char_array;
}
