//
//  string.cpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//



#include "string.hpp"
#include "helpers.hpp"


String::String() {
    std::cout << "Empty constructor" << std::endl;
    char_array = nullptr;
}


String::String(const char* chars) {
    std::cout << "Regular constructor" << std::endl;
    char_array = new char[helpers::strlen(chars)];
    helpers::strcpy(char_array, chars);
}


String::~String() {
    std::cout << "Destructor" << std::endl;
    delete[] char_array;
}


String::String(const String& other) {
    std::cout << "Copy constructor" << std::endl;
    char_array = new char[helpers::strlen(other.char_array)];
    helpers::strcpy(char_array, other.char_array);
}


String::String(String&& other) {
    std::cout << "Move constructor" << std::endl;
    char_array = other.char_array;
}


String& String::operator=(const String& other) {
    std::cout << "Copy Assignment" << std::endl;
    helpers::dyn_strcpy(char_array, other.char_array);
    return *this;
}


String& String::operator=(String&& other) {
    std::cout << "Move Assignment" << std::endl;
    std::swap(char_array, other.char_array);
    return *this;
}


char& String::operator[](const unsigned& index) const {
    return char_array[index];
}


std::ostream& operator<<(std::ostream& os, const String& string) {
    return os << string.char_array;
}
