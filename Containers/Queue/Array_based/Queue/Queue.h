//
//  Queue.h
//  Queue
//
//  Created by Adam Saher on 19/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Queue_h
#define Queue_h



template <typename T>
struct Queue {
    T* queue_;
    static const unsigned INITIAL_CAPACITY;
    unsigned capacity_;
    unsigned front_index_;
    unsigned back_index_;  //index of the next available spot, not the last element.
    unsigned size_;
public:
    Queue();
    /**
     Append a value of type T to the queue

     @param T& The value needed to be appended to the queue passed by reference
     */
    void enqueue(const T&);
    
    
    /**
     If the queue is not empty, remove the first value from the queue
     */
    void dequeue();
    
    
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
const unsigned Queue<T>::INITIAL_CAPACITY = 3;


template <typename T>
Queue<T>::Queue() {
    queue_ = new T[INITIAL_CAPACITY];
    capacity_ = INITIAL_CAPACITY;
    front_index_ = back_index_ = size_ = 0;
}


template <typename T>
void Queue<T>::enqueue(const T& data) {
    queue_[back_index_] = data;
     ++size_;
    back_index_ = ((back_index_ + 1) % capacity_);
    //If the array is full, grow it.
    if (size_ == capacity_)
        grow();
}


template <typename T>
void Queue<T>::dequeue() {
    if (size_) {
        front_index_ = (front_index_ + 1) % capacity_;
        --size_;
    }
}


template <typename T>
T Queue<T>::peek() const {
    return (empty()? T{} : queue_[front_index_]);
}


template <typename T>
bool Queue<T>::empty() const {
    return size_ == 0;
}


template <typename T>
void Queue<T>::grow() {
    T* tmp = new T[capacity_ * 2];
    for (unsigned i = 0u; i < size_; ++i)
        tmp[i] = queue_[(front_index_ + i) % capacity_];
    std::swap(tmp, queue_);
    delete[] tmp;
    front_index_ = 0;
    back_index_ = capacity_;
    capacity_ *= 2;
}


#endif /* Queue_h */
