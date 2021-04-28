//
//  square.cpp
//  Shape
//
//  Created by Adam Saher on 2021-04-02.
//

#include "square.hpp"

Square::Square(unsigned num_of_angles, double side) : RegularPolygon(side) {};


float Square::area() const {
    return side * side;
}


float Square::perimeter() const {
    return 4 * side;
}
