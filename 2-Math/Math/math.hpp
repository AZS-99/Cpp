//
//  math.hpp
//  Math
//
//  Created by Adam Saher on 2021-03-04.
//

#ifndef math_hpp
#define math_hpp

#include <iostream>
namespace math {
    
    double log(const unsigned&);
    double sqrt(const double&);
    float approx(const double&, const unsigned& = 0);
    unsigned count_digits(const int&);
    unsigned count_regions(const unsigned&);
    unsigned first_digit(const unsigned&);
    unsigned factorial(const unsigned&);
    unsigned gcd(unsigned, unsigned);
    unsigned reverse(const unsigned& num);
    unsigned summation(const unsigned&);
    unsigned sum_digits(const unsigned&);
    unsigned reverse(const unsigned&);
    



    template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
    T abs(const T& num) {
        return num < 0?  0 - num : num;
    }


    template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
    auto max(const T& value1, const T& value2) {
        return value1 > value2? value1 : value2;
    }


    template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
    T power(const T& base, const unsigned& exponent) {
        return (exponent == 0) ? 1 : power(base, exponent - 1) * base;
    }



    template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
    T sum(const T* array, const unsigned& size) {
        T total = T{};
        for (unsigned i = 0; i < size; ++i)
            total += array[i];
        return total;
    }


    



}

#endif /* math_hpp */
