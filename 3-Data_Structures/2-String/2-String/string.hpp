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
    String(const String&);//Case: Definition by equating to another instance.
    String(String&&);
    String& operator=(const String&);  //The return is not void, to allow for chaining:  a = b = c
    String& operator=(String&&);        //When an already initiated instance is equated to a regular constructor
    char& operator[](const unsigned&) const;
    friend std::ostream& operator<<(std::ostream&, const String&);
};

#endif /* string_hpp */


/*
 Notes:
 
 1- Declarations and definitions use ONLY constructors.
 
 2- Empty constructor is called by a plain declarations (has no defintion), or a definition with no arguments.
 
 3- Regular constructor is executed whenever the name of the calss is called by passing parameters; i.e. String("hi")
 
 4- Copy constructor is executed when an equal sign (=) rests between an instance that is being declared, and a predefined instance.
 
 5- Copy assignment is used whenever the equal sign rests between two predefined instances.
    It returns a reference for saving processes during chaining
    When you set c = b = a, b = a is executed first, think of it as c = (b = a)
    This b = a is now a fn on its own, and returns by value. You need to return either a pointer
    or a reference instead to avoid returning by value.
 
 6- Move assignment is when a predeclared/predefined instance is equated to regular constructor: str = String("new");
 
 
 */