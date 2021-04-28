//
//  school.cpp
//  School
//
//  Created by Adam Saher on 2021-04-27.
//

#include "school.hpp"

School::School(const char* name) {
    this->name = name;
    students = std::vector<Student*>();
}


void School::add_student(Student& student) {
    students.push_back(&student);
}
