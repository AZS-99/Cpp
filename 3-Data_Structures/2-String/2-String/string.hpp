//
//
//  Created by Adam Saher on 2021-03-16.
//

#ifndef string_hpp
#define string_hpp


#include <iostream>

class String {
    char* char_array;
public:
    String();
    String(const char*);
    ~String();
    String(const String&);
    friend std::ostream& operator<<(std::ostream&, const String&);
};

#endif /* string_hpp */
