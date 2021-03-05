//
//  String.cpp
//  String
//
//  Created by Adam Saher on 05/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include "String.hpp"

String::String () {
    std::cout << "Empty Constructor" << std::endl;
    _string = nullptr;
    _size = 0;
}


String::String (const char* str) {
    std::cout << "Regular Constructor" << std::endl;
    _size = strlen(str);
    _string = new char [_size + 1];
    strcpy (_string, str);
}


String::~String () {
    std::cout << "Delete" << std::endl;
    delete[] _string;  //Any error here means a dangling pointer
}


String::String(const String& src) {
    std::cout << "Copy Constructor" << std::endl;
    _size = src._size;
    if (src._string) {
        _string = new char[_size + 1];
        strcpy(_string, src._string);
    } else  //In case of equating to an empty string.
        _string = nullptr; //Or *this = String (), which would cost you an empty constructor + copy assignment, but eleminate redundancy in case of changes to constructos (adding a member)
}


String& String::operator=(const String& src) {
    std::cout << "copy assignment operator" << std::endl;
    if (this != &src) {
        if (_size && _size == src._size)
            strcpy (_string, src._string);
        else {
            delete[] _string;
            _size = src._size;
            if (src._string) {
                _string = new char [_size + 1];
                strcpy (_string, src._string);
            } else
                _string = nullptr;
        }
    }
    return *this;
}


String::String(String&& src) {
    std::cout << "Move Constructor" << std::endl;
    _string = src._string;
    _size = src._size;
    src._size = 0;
    src._string = nullptr;
}


String& String::operator=(String&& src) {
    std::cout << "Move Assignment" << std::endl;
    std::swap(_string, src._string);
    std::swap(_size, src._size);
    return *this;
}


std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << (str._string? str._string : ""); //counting for empty constructor 
}


char& String::operator[](unsigned index) const {
    return _string[index];
}


char& String::at(unsigned index) const{
    if (index > _size - 1)
        throw std::out_of_range("The index you have entered is out of bounds");
    return _string[index];
}


char& String::back() const {
    return _string[_size - 1];
}


bool String::empty() const {
    return _size == 0;
}


