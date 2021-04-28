//
//  shape.hpp
//  Shape
//
//  Created by Adam Saher on 2021-04-03.
//

#ifndef shape_hpp
#define shape_hpp

#include <stdio.h>

class iShape {
    virtual float area() const = 0;  //Without the = 0, the compiler will look for an implementation in this class
    virtual float perimeter() const = 0;
};


#endif /* shape_hpp */
