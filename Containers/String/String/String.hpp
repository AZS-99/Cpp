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
    char* _string;
    size_t _size;
    friend std::ostream& operator<<(std::ostream&, const String&);
public: //The Rule of Five
    String();
    String(const char*);
    ~String();
    String(const String&);
    String(String&&);
    String& operator=(const String&); //The return is not void just for chaining:  a = b = c  
    String& operator=(String&&);
    char& operator[](unsigned) const; //const promises that no data member will be changed within the method
    bool empty() const;
    char& at(unsigned) const;
    char& back() const;
};


/*
 Rule of 5
 - A constructor is used whenever String() is called
 - If it's used within a defintion, its value is assigned to the variable
 - Empty constructor is used in case of declarations with no definition, or definitions with no args.
 - Constructors are used only in declarations/definitons: auto str = String("Adam")
 - Copy assignment is used only when the operator (=) is between two predefined instances: str1 = str2
 
 
 */



#endif /* String_hpp */
