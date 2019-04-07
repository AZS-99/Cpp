//
//  Node.cpp
//  Node
//
//  Created by Adam Saher on 06/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include "Node.hpp"

template <typename T>
Node<T>::Node(T data, Node* left, Node* right) {
    data_ = data;
    left_ = left;
    right_ = right;
}

Node<int> node;
