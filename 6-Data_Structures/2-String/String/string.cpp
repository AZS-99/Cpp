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
    data_ = nullptr;
}


String::String(const char* chars) {
    std::cout << "Regular constructor" << std::endl;
    data_ = new char[helpers::strlen(chars) + 1];
    helpers::strcpy(data_, chars);
}


String::~String() {
    std::cout << "Destructor" << std::endl;
    delete[] data_;
}


String::String(const String& other) {
    std::cout << "Copy constructor" << std::endl;
    data_ = new char[helpers::strlen(other.data_)];
    helpers::strcpy(data_, other.data_);
}


String::String(String&& other) {
    std::cout << "Move constructor" << std::endl;
    data_ = other.data_;
}


String& String::operator=(const String& other) {
    std::cout << "Copy Assignment" << std::endl;
    helpers::dyn_strcpy(data_, other.data_);
    return *this;
}


String& String::operator=(String&& other) {
    std::cout << "Move Assignment" << std::endl;
    std::swap(data_, other.data_);
    return *this;
}


bool String::empty() const {
    return data_ == nullptr;
}


bool String::palindrome() const {
    auto left = data_;
    auto right = data_ + length() - 1;
    while (left < right) {
        if (*left++ != *right--)
            return false;
    }
    return true;
}


char& String::operator[](const unsigned& index) const {
    return data_[index];
}


const char* String::data() const {
    return data_;
}


unsigned String::length() const {
    auto len = 0u;
    auto ptr = data_;
    while (*ptr++ != '\0') ++len;
    return len;
}


// Find the longest substring
unsigned String::max_substring_len() const {
    if (empty())
        return 0;
    const unsigned ASCII_COUNT = 256;
    bool used_letters[ASCII_COUNT] = {0};
    
    auto left = data_;
    auto right = left;
    
    auto substring_len = 0u;
    auto max_len = 0u;
    do {
        while (*right != '\0' && !used_letters[(int)*right]) {
            used_letters[(int)*right++] = true;
            ++substring_len;
        }
        
        max_len = max_len > substring_len? max_len : substring_len;
        if (*right == '\0')
            return max_len;
        while (*left != *right) {
            used_letters[(int)*left++] = false;
            --substring_len;
        }
        used_letters[(int)*left++] = false;
        --substring_len;
    } while (*right != '\0');
    return max_len;
}


void impress_on_array(bool* array, const char& ch) {
    array[ch - 'a'] = true;
}


std::ostream& operator<<(std::ostream& os, const String& string) {
    return os << string.data_;
}
