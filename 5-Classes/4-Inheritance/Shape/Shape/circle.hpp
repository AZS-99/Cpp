//
//  Circle.hpp
//  Shape
//
//  Created by Adam Saher on 2021-04-02.
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>
#include "shape.hpp"

class Circle : public iShape {
    double radius;
public:
    float area() const;
    float perimeter() const;
};

#endif /* Circle_hpp */
