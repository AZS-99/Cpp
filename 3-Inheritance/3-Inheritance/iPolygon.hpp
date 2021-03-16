//
//  iPolygon.hpp
//  3-Inheritance
//
//  Created by Adam Saher on 2021-03-14.
//

#ifndef iPolygon_hpp
#define iPolygon_hpp

#include <stdio.h>

class iPolygon {
    virtual unsigned get_area() const = 0;
    virtual unsigned get_perimeter() const = 0;
};
#endif /* iPolygon_hpp */
