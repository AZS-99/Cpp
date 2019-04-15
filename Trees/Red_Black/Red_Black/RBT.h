//
//  RBT.h
//  Red_Black
//
//  Created by Adam Saher on 14/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef RBT_h
#define RBT_h

#include "Node.h"

template <typename T>
class RBT {
    Node<T>* root_;
public:
    RBT();
    void insert(const T& data);
private:
    static void insert(Node<T>*&, Node<T>*, const T&);
};


template <typename T>
inline RBT<T>::RBT() {
    root_ = nullptr;
}


template <typename T>
void RBT<T>::insert(const T &data) {
    insert(root_, nullptr, data);
}


template <typename T>
void RBT<T>::insert(Node<T>*& node, Node<T>* parent, const T &data) {
    if (!node) {
        node = new RBT(data, false);
        node->parent_ = parent;
    }
    else if (data < node->data_) {
        parent = node->left_->parent_;
        insert(node->left_, parent, data);
    }
    else if (data > node->data_) {
        parent = node->right_->parent;
        insert(node->right_, data);
    }
}

#endif /* RBT_h */
