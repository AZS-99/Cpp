//
//  square.hpp
//  Shape
//
//  Created by Adam Saher on 2021-04-02.
//

#ifndef square_hpp
#define square_hpp

#include <stdio.h>
#include "regular_polygon.hpp"

class Square : protected RegularPolygon {
public:
    Square(unsigned num_of_angles, double side);
    float area() const;
    float perimeter() const;
};

#endif /* square_hpp */
