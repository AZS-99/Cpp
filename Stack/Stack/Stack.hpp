//
//  Stack.hpp
//  Stack
//
//  Created by Adam Saher on 07/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include <list>

template <typename T>
class Stack {
    std::list<T> stack_;
public:
    void push(const T& data) {
        stack_.push_back(data);
    }
    
    T top() const {
        return *(--stack_.end());
    }
    
    bool isEmpty() const {
        return stack_.cbegin() == stack_.cend();
    }
};

#endif /* Stack_h */
