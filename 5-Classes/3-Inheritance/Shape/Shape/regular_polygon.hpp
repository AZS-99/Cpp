//
//  RegularPolygon.hpp
//  Shape
//
//  Created by Adam Saher on 2021-04-02.
//

#ifndef RegularPolygon_hpp
#define RegularPolygon_hpp

#include <stdio.h>
#include "shape.hpp"
#include <math.h>

class RegularPolygon : public iShape {
protected:
    double side;
public:
    RegularPolygon(double side);
};


/*
 ReuglarPolygon automatically inherits the perimiter and the area methods. Since they are not defined here, this class
 is ABSTRACT and cannot be initialised. For a class to be initialisable, all symbols/signatures have to be defined.
 It is not an interface like Shape, because ALL methods in Shape are virtual and equated
 to zero.
 */

#endif /* RegularPolygon_hpp */
