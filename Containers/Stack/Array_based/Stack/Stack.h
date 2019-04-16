//
//  Stack.h
//  Stack
//
//  Created by Adam Saher on 19/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Stack_h
#define Stack_h


template <class T>
class Stack {
    T* stack_;
    static const unsigned INITIAL_CAPACITY;
    unsigned capacity_;
    unsigned size_;
    
public:
    Stack();
    void push(const T& data);
    void pop();
    bool is_empty();
    T peek() const;
    
private:
    void grow();
};


template <typename T>
const unsigned Stack<T>::INITIAL_CAPACITY = 10;


template <typename T>
Stack<T>::Stack() {
    capacity_ = INITIAL_CAPACITY;
    stack_ = new T[capacity_];
    size_ = 0u;
}


template <typename T>
bool Stack<T>::is_empty() {
    return size_ == 0u;
}


template <typename T>
void Stack<T>::push(const T& data) {
    stack_[size_++] = data;
    if (size_ == capacity_)
        grow();
}


template <typename T>
void Stack<T>::pop() {
    --size_;
}


template <typename T>
T Stack<T>::peek() const {
    return (size_ > 0? stack_[size_ - 1] : T{});
}


template <typename T>
void Stack<T>::grow() {
    capacity_ *= 2;
    T* tmp = new T[capacity_];
    for (auto i = 0u; i < size_; ++i)
        tmp[i] = stack_[i];
    std::swap(stack_, tmp);
    delete[] tmp;
}


#endif /* Stack_h */
