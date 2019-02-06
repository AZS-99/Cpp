//
//  Math.cpp
//  Math
//
//  Created by Adam Saher on 01/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include "Math.hpp"

namespace math {
    
    double approximate(const double& num, unsigned precision) {
        return approximate(num * pow(10, precision))/pow(10, precision);
    }
    
    
    double approximate(const double& num) {
        if (num - 0.5 >= floor(num))
            return floor(num) + 1;
        return floor(num);
    }
    
    
    double floor(const double& num) {
        return (unsigned long long) num;
    }
    
    
    double sqrt(const double& x) {
        if (x <= 1)
            return x;
        return sqrt(x/1.001) * 1.0005;
    }
    
    
    size_t* split(size_t num) {
        unsigned size = number_of_digits(num);
        size_t* array = new size_t[size];
        for (int i = size - 1; i >= 0; --i) {
            array[i] = num % 10;
            num /= 10;
        }
        return array;
    }
    
    
    size_t sum(const size_t& a) {
        size_t total = 0;
        for (auto i = 0u; i <= a; ++i)
            total += i;
        return total;
    }
    
    
    size_t sum(const size_t& a, const size_t& b) {
        size_t total = 0;
        for (auto i = a; i <= b; ++i)
            total += i;
        return total;
    }
    
    
    unsigned int number_of_digits(const size_t& num) {
        if (num < 9)
            return 1;
        return number_of_digits(num / 10) + 1;
    }
}
