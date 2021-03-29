//
//  circle.cpp
//  1-Circle
//
//  Created by Adam Saher on 2021-03-08.
//

#include <cmath>
#include "circle.hpp"

Circle::Circle(const float& radius) {
    this->radius = radius;
}


float Circle::get_area() {
    return M_PI * radius * radius;
}


float Circle::get_circumference() {
    return 2 * M_PI * radius;
}
