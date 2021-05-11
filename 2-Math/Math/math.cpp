//
//  math.cpp
//  Math
//
//  Created by Adam Saher on 2021-03-04.
//

#include "math.hpp"
#include <cmath>

namespace {

    double sqrt_search (const double& num, double& min, double& max) {
        double mid = (min + max)/2;
        double sqr = mid * mid;
        if (sqr < num + 1 && sqr > num - 1)
            return mid;
        else {
            if (sqr > num)
                return sqrt_search(num, min, mid);
            else
                return sqrt_search(num, mid, max);
        }
    }
}


namespace math {

    unsigned first_digit(const unsigned& num) {
        return num / std::pow(10, count_digits(num));
    }


    unsigned reverse(const unsigned& num) {
        if (num < 10)
            return num;
        auto count_digits_ = count_digits(num);
        auto last_digit = num % 10;
        return reverse((num / 10)) + last_digit * std::pow(10, count_digits_ - 1);
    }


    float approx(const double& num, const unsigned& precision) {
        unsigned factor = power(10, precision + 1);
        int factored_num = num * factor;
        unsigned last_digit = factored_num % 10;
        
        if (last_digit > 4)
            return float(factored_num + 10 - last_digit)/factor;
        else
            return float(factored_num - last_digit)/factor;
    }

    

    double sqrt(const double& num) {
        double min = 1;
        double max = num;
        return sqrt_search(num, min, max);
    //    if (num != 1) {
    //        double max = num > 1? num : 1;
    //        double min = num > 1? 1 : num;
    //        double mid = (max + min)/2;
    //        float margin = 0.001;
    //
    //        while(!(mid * mid < num + margin && mid * mid > num - margin)) {
    //            if (mid * mid > num)
    //                max = mid;
    //            else
    //                min = mid;
    //            mid = (max + min) / 2;
    //        }
    //        return mid;
    //    }
    //    else
    //        return 1.0;
        
    }

    

    /*
     RECURSION
     */
    unsigned count_digits(const int& num) {
        return std::floor(std::log10(num)) + 1;
    }

/// Return the max number of regions a plane could be cut into using n lines.
/// @param n number of lines cutting the plane
    unsigned count_regions(const unsigned& n) {
        if (n < 2)
            return n;
        return count_regions(n - 1) + n; //Every added line cuts AT MOST all other lines, creating new region with each intersection.
    }


    unsigned factorial(const unsigned& num) {
        return num == 1? 1 : factorial(num - 1) * num;
    }


    unsigned gcd(unsigned num1, unsigned num2) {
        if (num1 < num2)
            std::swap(num1, num2);
        return num1 % num2 == 0 ? num2 : gcd(num2, num1 % num2);
    }

    
    


    unsigned summation(const unsigned& num) {
        return num < 2? num : summation(num - 1) + num;
    }

    
    unsigned sum_digits(const unsigned& num) {
        return num < 10? num : sum_digits(num / 10) + sum_digits(num % 10);
    }


}
