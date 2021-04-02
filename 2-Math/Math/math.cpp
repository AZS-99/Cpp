//
//  math.cpp
//  Math
//
//  Created by Adam Saher on 2021-03-04.
//

#include "math.hpp"

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


unsigned count_digits(const int& num) {
    return abs(num) < 10? 1 : count_digits(num/10) + 1;
}


unsigned factorial(const unsigned& num) {
    return num == 1? 1 : factorial(num - 1) * num;
}


unsigned gcd(unsigned num1, unsigned num2) {
    if (num1 < num2)
        std::swap(num1, num2);
    return num1 % num2 == 0 ? num2 : gcd(num2, num1 % num2);
}



}
