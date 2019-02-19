//
//  Queue.h
//  Queue
//
//  Created by Adam Saher on 19/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <list>

template <typename T>
class Queue {
    std::list<T> queue_;
public:
    void push(const T&);
    void pop();
    bool empty() const;
};


template <typename T>
void Queue<T>::push(const T& data) {
    queue_.push_back(data);
}


template <typename T>
void Queue<T>::pop() {
    queue_.pop_front();
}


template <typename T>
bool Queue<T>::empty() const {
    return queue_.empty();
}

#endif /* Queue_h */
