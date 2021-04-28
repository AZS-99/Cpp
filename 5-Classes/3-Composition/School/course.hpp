//
//  course.hpp
//  School
//
//  Created by Adam Saher on 2021-04-27.
//

#ifndef course_hpp
#define course_hpp

#include <string>

class Course {
    std::string name;
    std::string id;
public:
    Course(const char*, const char*);
};

#endif /* course_hpp */
