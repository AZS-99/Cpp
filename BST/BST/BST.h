//
//  BST.h
//  BST
//
//  Created by Adam Saher on 19/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <queue>
#include "Node.h"

template <typename T>
class BST {
    Node<T>* root_;
public:
    BST();
    ~BST();
    bool exists(const T&);
    std::ostream& display(std::ostream&) const;
    void iterative_insert(const T& value);
    void recursive_insert(const T& value);
    void remove(const T&);
private:
    void insert(Node<T>*& current, const T& value);
    std::ostream& displayNode(std::ostream&, const Node<T>*);
};


template <typename T>
BST<T>::BST() {
    root_ = nullptr;
}


template <typename T>
void BST<T>::iterative_insert(const T &value) {
    if (!root_) {
        root_ = new Node<T>(value);
        return;
    }
    auto current = root_;
    while (current->left || current->right) {
        if (current->left && current->data_ < value )
            current = current->left;
    }
}


template <typename T>
void BST<T>::recursive_insert(const T &value) {
    insert(root_, value);
}


template <typename T>
void BST<T>::insert(Node<T>*& current, const T& value) { //pass the pointer by reference!
    if (!current)
        current = new Node<T>(value);
    else {
        if (value < current->data_)
            insert(current->left_, value);
        else
            insert(current->right_, value);
    }
}


template <typename T>
std::ostream& BST<T>::display(std::ostream&) const {
    displayNode(root_);
}


template <typename T>
std::ostream& BST<T>::displayNode(std::ostream& os, const Node<T>* current) {
    if (!current)
        return os << "|";
    std::queue<Node<T>*> q;
    q.enqueue(root_);
    while (!q.empty()) {
        
    }
    
}

#endif /* BST_h */
