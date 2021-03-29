//
//  Queue.h
//  Queue
//
//  Created by Adam Saher on 2021-03-24.
//

#ifndef Queue_h
#define Queue_h

template <typename T>
class Queue {
    static const unsigned INITIAL_CAPACITY;
    T* queue;
    unsigned capacity;
    unsigned size;
    void grow();
public:
    Queue();
    void push(const T& value);
    T peek() const;
    T pop();
};


template <typename T>
const unsigned Queue<T>::INITIAL_CAPACITY = 10u;


template <typename T>
Queue<T>::Queue() {
    queue = new T[INITIAL_CAPACITY]();
    capacity = INITIAL_CAPACITY;
    size = 0u;
}


template <typename T>
void Queue<T>::push(const T& value) {
    if (size == capacity)
        grow();
    queue[size++] = value;
}


template <typename T>
void Queue<T>::grow() {
    auto tmp = new T[capacity * 2];
    for (auto i = 0u; i < size; ++i)
        tmp[i] = queue[i];
    delete[] queue;
    queue = tmp;
}


template <typename T>
T Queue<T>::peek() const {
    return queue[size - 1];
}


template <typename T>
T Queue<T>::pop() {
    return queue[--size];
}

#endif /* Queue_h */
