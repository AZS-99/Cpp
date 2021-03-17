//
//  string.hpp
//  2-String
//
//  Created by Adam Saher on 2021-03-16.
//

#ifndef string_hpp
#define string_hpp


#include <iostream>

class String {
    char* string;
public:
    String();
    String(const char*);
    std::ostream& print(std::ostream&) const;
};

#endif /* string_hpp */
