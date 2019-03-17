//
//  String.hpp
//  String
//
//  Created by Adam Saher on 05/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <iostream>

class String {
    char* string_;
    size_t size_;
    friend std::ostream& operator<<(std::ostream& os, const String& str);
public:
    String();
    String(const char*);
    ~String();
    String(const String&);
    String(String&&);
    String& operator=(const String&);
    String& operator=(String&&);
    bool empty() const;
    char& operator[](unsigned) const;
    char& at(unsigned) const;
    char& back() const;
};




#endif /* String_hpp */
