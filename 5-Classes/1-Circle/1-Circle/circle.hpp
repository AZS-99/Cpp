//
//  circle.hpp
//  1-Circle
//
//  Created by Adam Saher on 2021-03-08.
//

#ifndef circle_hpp
#define circle_hpp

class Circle {
    float radius;
public:
    Circle(const float&);
    float get_area();
    float get_circumference();
};

#endif /* circle_hpp */
