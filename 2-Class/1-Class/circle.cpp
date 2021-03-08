//
//  Circle.cpp
//  1-Class
//
//  Created by Adam Saher on 2021-03-04.
//

#include <cmath>
#include "circle.hpp"

Circle::Circle(float r) {
    radius = r;
};


float Circle::get_area() {
    return M_PI * std::pow(radius, 2);
}


float Circle::get_circumference() {
    return 2 * M_PI * radius;
}
