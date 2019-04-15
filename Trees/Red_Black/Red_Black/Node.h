//
//  Node.h
//  Red_Black
//
//  Created by Adam Saher on 14/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <typename T> class RBT;

template <typename T>
class Node {
    T data_;
    bool red_;
    Node *left_, *right_, *parent_;
    friend RBT<T>;
public:
    Node(const T& data = T{}, const bool& red = true, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
    
};


template <typename T>
Node<T>::Node(const T& data, const bool& red, Node* parent, Node* left, Node* right) {
    data_ = data;
    red_ = red;
    left_ = left;
    right_ = right;
    parent_ = parent;
}

#endif /* Node_h */
