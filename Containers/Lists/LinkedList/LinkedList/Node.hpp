//
//  Node.hpp
//  LinkedList
//
//  Created by Adam Saher on 01/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Node_h
#define Node_h

namespace Container {
    template <typename T>
    class LinkedList;
    
    template <typename T>
    class Const_iterator;
    
    template <typename T>
    class Node {
        T data_;
        Node* nxt_;
        Node* prev_;
        Node(const T& data = T{}, Node* nxt = nullptr, Node* prev = nullptr);
        friend LinkedList<T>;
        friend Const_iterator<T>;
    };
    
    
    template <typename T>
    Node<T>::Node(const T& data, Node* nxt, Node* prev) {
        nxt_ = nxt;
        prev_ = prev;
        data_ = data;
    }
}

#endif /* Node_h */
