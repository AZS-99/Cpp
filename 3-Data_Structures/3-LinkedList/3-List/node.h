//
//  node.h
//  3-LinkedList
//
//  Created by Adam Saher on 2021-03-18.
//

#ifndef node_h
#define node_h

template <typename T> class List;
template <typename T> class const_iterator;


template <typename T>
class Node {
    T value;
    Node* nxt;
    Node* prev;
    Node(const T& = T{}, Node* = nullptr, Node* = nullptr);
    friend List<T>;
    friend const_iterator<T>;
};


template <typename T>
Node<T>::Node(const T& value, Node* next, Node* previous) {
    this->value = value;
    this->nxt = next;
    this->prev = previous;
}

#endif /* node_h */