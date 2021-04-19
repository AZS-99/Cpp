//
//  main.cpp
//  Miscelaneous
//
//  Created by Adam Saher on 2021-04-10.
//

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <typeinfo>

// O(n)
unsigned count_digits(const unsigned& num) {
    return (num < 10)? 1 : count_digits(num / 10) + 1;
}


// O(n)
unsigned left_digit(const unsigned& num) {
    return num < 10? num : left_digit(num / 10);
}


// An array that starts with units, then tens, ...
std::vector<unsigned> split_into_digits(unsigned num) {
    unsigned digits_count = count_digits(num);
    std::vector<unsigned> digits(digits_count);
    
    for (auto i = 0u; i < digits_count; ++i) {
        digits[i] = num % 10;
        num /= 10;
    }
    digits[digits_count] = '\0';
    return digits;
}


std::string roman(const int& num) {
    int power = std::pow(10, count_digits(num) - 1);
    if (num % power == 0) {
        auto left_d = left_digit(num);
        
    }
    std::string roman_num = roman(num/10);
    unsigned index = count_digits(num) - 1;
    const unsigned left_d = left_digit(num);
    std::string numerals[] = {"I", "V", "X", "L", "C", "D", "M"};
    
    if (left_d < 4) {
        for (auto i = 0u; i < left_d; ++i)
            roman_num.insert(0, numerals[index]);
    }
    return roman_num;
}

// Convert a number to Roman representation
std::string convert_to_roman(const int& num) {
    auto digits = split_into_digits(num);
    char* roman_numerals[] = {"I", "V", "X", "L", "C", "D", "M"};
    
    std::string roman, tmp;
    unsigned digit;
    for (auto i = 0u; i < count_digits(num); ++i) {
        digit = digits[i];
        if (digit < 4) {
            for (auto j = 0; j < digit; ++j) roman.insert(0, roman_numerals[i]);
        } else if (digit == 4) {
            roman.insert(0, roman_numerals[i + 1]);
        } else if (digit < 9) {
            for (auto j = 0; j < digit - 5; ++j) roman.insert(0, roman_numerals[i + 1]);
            roman.insert(0, roman_numerals[i + 2]);
            
        } else {
            roman.insert(0, roman_numerals[i]);
            roman.insert(0, roman_numerals[i+2]);
        }
    }
    return roman;
}



//find possible combinations of string for a dialled number
std::vector<std::string> string_combinations(const std::string num_str) {
    const std::map<char, std::set<char>> dictionary = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    std::vector<std::string> result, tmp;
    std::string s;
    result.push_back("");
    std::set<char> set;
    for (auto& digit : num_str) {
        set = dictionary.find(digit)->second;
        
    }

    return result;
}


int main(int argc, const char * argv[]) {
    
    auto vec = string_combinations("23");
    for (auto& string : vec)
        std::cout << string << std::endl;

    return 0;
}
