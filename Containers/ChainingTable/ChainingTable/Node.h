//
//  Node.hpp
//  SortedList
//
//  Created by Adam Saher on 16/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
template <typename T> class SortedList;

template <typename T>
class Node {
    T data_;
    Node* nxt_;
    Node* prev_;
    Node(const T& data = T{}, Node* nxt = nullptr, Node* prev_ = nullptr);
    friend SortedList<T>;
};


/// Create a node holding a value: data, and a pointer to the next node and the previous one.
template <typename T>
Node<T>::Node(const T& data, Node* nxt, Node* prev){
    data_ = data;
    nxt_ = nxt;
    prev_ = prev;
}
#endif /* Node_hpp */
