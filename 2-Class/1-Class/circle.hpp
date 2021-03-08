//
//  Circle.hpp
//  1-Class
//
//  Created by Adam Saher on 2021-03-04.
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>

class Circle {
    float radius;
    
public:
    Circle(float radius);
    float get_area();
    float get_circumference();
};

#endif /* circle_hpp */
