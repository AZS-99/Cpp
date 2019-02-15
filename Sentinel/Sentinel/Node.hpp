//
//  Node.hpp
//  Sentinel
//
//  Created by Adam Saher on 13/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <typename T> class Sentinel;

template <typename T>
class Node {
    T data_;
    Node* nxt_;
    Node* prev_;
    Node(const T& data = T{}, Node* nxt = nullptr, Node* prev = nullptr);
    friend Sentinel<T>;
};

template <typename T>
Node<T>::Node(const T& data, Node* nxt, Node* prev) {
    data_ = data;
    nxt_ = nxt;
    prev_ = prev;
}

#endif /* Node_h */
