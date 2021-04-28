//
//  Circle.cpp
//  Shape
//
//  Created by Adam Saher on 2021-04-02.
//

#include <math.h>
#include "circle.hpp"

float Circle::area() const {
    return M_PI * radius * radius;
}


float Circle::perimeter() const {
    return 2 * radius * M_PI;
}
