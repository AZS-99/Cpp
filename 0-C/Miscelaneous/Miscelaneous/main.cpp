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
#include <list>

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


std::vector<int> min_coin_num(std::vector<int>& coins, int amount) {
    std::sort(coins.begin(), coins.end(), std::greater<int>());
    std::vector<int> denom_count(coins.size(), 0);
    auto count = 0u;
    
    std::transform(coins.cbegin(), coins.cend(), denom_count.begin(), [&amount, &count] (const int& coin) {
        auto res = amount / coin;
        count += res;
        amount %= coin;
        return res;
    });
    if (amount == 0)
        return denom_count;
    else
        return {};
    
}




int main(int argc, const char * argv[]) {
    std::vector<int> coins = {50, 20};
    auto vec = min_coin_num(coins, 160);
    for (auto& num : vec)
        std::cout << "amount of coin: " << num << std::endl;

    return 0;
}
