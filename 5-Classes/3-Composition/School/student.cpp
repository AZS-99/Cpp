//
//  student.cpp
//  School
//
//  Created by Adam Saher on 2021-04-27.
//

#include <iostream>
#include "student.hpp"

const unsigned Student::LIMIT = 1000;
unsigned Student::count = 0;


Student::Student(const char* name) : student_id(count++) {
    this->name = name;
}


std::ostream& operator<<(std::ostream& os, const Student& student) {
    return os << student.name;
}
