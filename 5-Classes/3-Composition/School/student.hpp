//
//  student.hpp
//  School
//
//  Created by Adam Saher on 2021-04-27.
//

#ifndef student_hpp
#define student_hpp

#include <iostream>
#include <string>

class Student {
    const static unsigned LIMIT;
    static unsigned count;
    std::string name;
    const unsigned student_id;
public:
    Student(const char* = nullptr);
    friend std::ostream& operator<<(std::ostream&, const Student&);
};


#endif /* student_hpp */
