//
//  Queue.h
//  Queue
//
//  Created by Adam Saher on 19/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

const unsigned INITIAL_CAPACITY = 5;

template <typename T>
class Queue {
    T* queue_;
    unsigned capacity_;
    unsigned front_index_;
    unsigned back_index_;
    unsigned size_;
public:
    Queue();
    /**
     Append a value of type T to the queue

     @param T& The value needed to be appended to the queue passed by reference
     */
    void push(const T&);
    
    
    /**
     Remove the first value from the queue
     */
    void pop();
    
    
    /**
     Return a copy of the first value in the queue.

     @return A copyt of the firstmost value in the queue.
     */
    T peek() const;
    
    
    /**
     Return whether there are no elements in the queue

     @return true if there are no elements in the queue, false otherwise.
     */
    bool empty() const;
    
    
    /**
     Copy the queue to another array that is twice the size of the current one,
     then delete the original array.
     */
    void grow();
};


template <typename T>
Queue<T>::Queue() {
    queue_ = new T[INITIAL_CAPACITY];
    capacity_ = INITIAL_CAPACITY;
    front_index_ = back_index_ = size_ = 0;
}


template <typename T>
void Queue<T>::push(const T & data) {
    queue_[back_index_] = data;
    ++size_;
    //If the array is full, grow it.
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
