//
//  Stack2.hpp
//  Stack
//
//  Created by Adam Saher on 14/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Stack2_h
#define Stack2_h

const size_t INITIAL_CAPACITY = 10;

template <class T>
class Stack2 {
    T* stack_;
    size_t capacity_;
    size_t size_;
    
public:
    Stack2();
    void push();
    void pop();
    bool is_empty();
    T peek() const;
    
private:
    void grow() {
        T* tmp = new T[2 * capacity_];
        for (auto i = 0u; i < size_; ++i)
            tmp[i] = stack_[i];
        std::swap(stack_, tmp);
        delete[] tmp;
        ++size_;
    }
};


template <typename T>
Stack2<T>::Stack2() {
    stack_ = new T[INITIAL_CAPACITY];
    size_ = 0u;
    capacity_ = INITIAL_CAPACITY;
}


template <typename T>
bool Stack2<T>::is_empty() {
    return size_ == 0;
}

#endif /* Stack2_h */
