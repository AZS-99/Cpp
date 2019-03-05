//
//  Math.hpp
//  Math
//
//  Created by Adam Saher on 01/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Math_hpp
#define Math_hpp

#include <iostream>
#include <type_traits>

namespace math {
    double approximate(const double& num);
    double approximate(const double& num, unsigned precision);
    double floor(const double& num);
    double sqrt(const double& x);
    size_t* split(size_t);
    size_t sum(const size_t&);
    size_t sum(const size_t&, const size_t&);
    unsigned number_of_digits(const size_t&);
    
    /**
     Return a random number between x and y

     @param x a positive integer included in the scope
     @param y a positive integer that is the end of the scope; included.
     @return a positive random number n, where x <= n <= y
     */
    unsigned random_between(unsigned x, unsigned y);
    
    
    template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
    double pow(const T& base, const size_t& exponent) {
        if (exponent == 0)
            return 1;
        return base * pow(base, exponent - 1);
    }
    
    
    template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
    T max(const T& a, const T& b) {
        return a > b? a : b;
    }
    
    
    template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
    T sum(const T* array, unsigned int size) {
        T total = 0;
        for (auto i = 0u; i < size; ++i)
            total += array[i];
        return total;
    }
}

#endif /* Math_hpp */
