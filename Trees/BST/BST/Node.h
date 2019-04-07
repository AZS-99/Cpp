//
//  Node.h
//  BST
//
//  Created by Adam Saher on 19/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Node_h
#define Node_h


template <typename T> class BST;

template <typename T>
class Node {
    T data_;
    Node* left_;
    Node* right_;
    friend BST<T>;
    template <typename U> friend void destroy(Node<U>*&);
    template <typename U> friend void insert_node(Node<U>*&, U);
public:
    Node(const T& data = T{}, Node* left = nullptr, Node* right = nullptr);
};

template <typename T>
Node<T>::Node(const T& data, Node* left, Node* right) {
    data_ = data;
    right_ = right;
    left_ = right;
}





#endif /* Node_h */
