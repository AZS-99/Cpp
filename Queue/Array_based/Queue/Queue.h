//
//  Queue.h
//  Queue
//
//  Created by Adam Saher on 19/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

const unsigned INITIAL_CAPACITY = 3;

template <typename T>
class Queue {
    T* queue_;
    unsigned capacity_;
    unsigned front_index_;
    unsigned back_index_;
public:
    Queue();
    void push(const T&);
    void pop();
    T peek() const;
    bool empty() const;
    void grow();
};


template <typename T>
Queue<T>::Queue() {
    queue_ = new T[INITIAL_CAPACITY];
    capacity_ = INITIAL_CAPACITY;
    front_index_ = back_index_ = 0;
}


template <typename T>
void Queue<T>::push(const T & data) {
    queue_[back_index_] = data;
    if ((back_index_ + 1) % capacity_ == front_index_) 
        grow();
    else
        back_index_ = ((back_index_ + 1) % capacity_);
}


template <typename T>
void Queue<T>::pop() {
    front_index_ = (front_index_ + 1) % capacity_;
}


template <typename T>
T Queue<T>::peek() const {
    return (!empty()? queue_[front_index_] : T{});
}


template <typename T>
bool Queue<T>::empty() const {
    return back_index_ == front_index_;
}


template <typename T>
void Queue<T>::grow() {
    T* tmp = new T[capacity_ * 2];
    for (unsigned i = 0u; i < capacity_; ++i)
        tmp[i] = queue_[(front_index_ + i + 1) % capacity_];
    std::swap(tmp, queue_);
    delete[] tmp;
    capacity_ *= 2;
    front_index_ = 0;
    back_index_ = capacity_ - 1;
}


#endif /* Queue_h */
