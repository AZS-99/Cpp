//
//  Polygon.hpp
//  3-Inheritance
//
//  Created by Adam Saher on 2021-03-14.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <stdio.h>
#include "iPolygon.hpp"

class RegularPolygon : public iPolygon {
    unsigned n;
    unsigned side_length;
};

#endif /* Polygon_hpp */
