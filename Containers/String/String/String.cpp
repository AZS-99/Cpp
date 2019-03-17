//
//  String.cpp
//  String
//
//  Created by Adam Saher on 05/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include "String.hpp"

String::String() {
    string_ = nullptr;
    size_ = 0;
}


String::String(const char* str) {
    size_ = strlen(str);
    string_ = new char[size_ + 1];
    strcpy(string_, str);
}


String::~String() {
    delete[] string_;
}


String::String(const String& src) {
    size_ = src.size_;
    string_ = new char[size_ + 1];
    strcpy(string_, src.string_);
}


String& String::operator=(const String& src) {
    if (this != &src) {
        delete[] string_;
        size_ = src.size_;
        string_ = new char[size_ + 1];
        for (auto i = 0u; i < size_; ++i)
            string_[i] = src.string_[i];
        string_[size_] = '\0';
    }
    return *this;
}


String::String(String&& src) {
    string_ = src.string_;
    size_ = src.size_;
    src.size_ = 0;
    src.string_ = nullptr;
}


String& String::operator=(String&& src) {
    std::swap(string_, src.string_);
    std::swap(size_, src.size_);
    return *this;
}


std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << (str.string_? str.string_ : " ");
}


char& String::operator[](unsigned index) const {
    return string_[index];
}


char& String::at(unsigned index) const{
    if (index > size_ - 1)
        throw std::out_of_range("The index you have entered is out of bounds");
    return string_[index];
}


char& String::back() const {
    return string_[size_ - 1];
}


bool String::empty() const {
    return size_ == 0;
}


