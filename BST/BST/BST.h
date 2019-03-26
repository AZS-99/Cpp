//
//  BST.h
//  BST
//
//  Created by Adam Saher on 19/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.

//ADD TO YOUR CODE: perfectly balanced, compleste, heght balanced

#ifndef BST_h
#define BST_h

#include <iostream>
#include <queue>
#include <string>
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
    void insert(const T& value);
    void remove(const T&);
    void remove (Node<T>*& node, const T&);
private:
    void recursive_insert(Node<T>*& current, const T& value);
    std::ostream& displayNode(std::ostream&, const Node<T>*) const;
    void destroy(Node<T>*&);
    template <typename U> friend std::ostream& operator<<(std::ostream& os, const BST<U>& bst);
};


template <typename T>
BST<T>::BST() {
    root_ = nullptr;
}


template <typename T>
BST<T>::~BST<T>() {
    destroy(root_);
}


template <typename T>
void BST<T>::destroy(Node<T>*& node) {
    if (!node)
        return;
    destroy(node->left_);
    destroy(node->right_);
    delete node;
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
void BST<T>::insert(const T &value) {
    recursive_insert(root_, value);
}


template <typename T>
void BST<T>::recursive_insert(Node<T>*& current, const T& value) { //pass the pointer by reference!
    if (!current)
        current = new Node<T>(value);
    else {
        if (value < current->data_)
            recursive_insert(current->left_, value);
        else
            recursive_insert(current->right_, value);
    }
}


template <typename T>
std::ostream& BST<T>::display(std::ostream& os) const {
    displayNode(os, root_);
    return os;
}


template <typename T>
std::ostream& BST<T>::displayNode(std::ostream& os, const Node<T>* current) const {
    if (!current)
        return os << "|";
    std::queue<Node<T>*> q;
    q.push(root_);
    while (!q.empty()) {
        Node<T>* tmp = q.front();
        q.pop();
        os << tmp->data_ << std::endl;
        if (tmp->left_)
            q.push(tmp->left_);
        if (tmp->right_)
            q.push(tmp->right_);
    }
    return os;
}


template <typename T>
void BST<T>::remove(const T& data) {
    remove(root_, data);
}


template <typename T>
void BST<T>::remove(Node<T>*& current, const T& data) {
    if (!current) {
        if (data == current->data_) {
            
        }
        else if (data < current->data_)
            remove(current->left_, data);
        else
            remove(current->right_, data);
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& bst) {
    bst.displayNode(os, bst.root_);
    return os;
}

#endif /* BST_h */
