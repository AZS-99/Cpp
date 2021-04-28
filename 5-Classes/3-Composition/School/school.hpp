//
//  school.hpp
//  School
//
//  Created by Adam Saher on 2021-04-27.
//

#ifndef school_hpp
#define school_hpp

#include <string>
#include <vector>
#include "student.hpp"

class School {
    std::string name;
    std::vector<Student*> students;
public:
    School(const char*);
    void add_student(Student&);
};

#endif /* school_hpp */
