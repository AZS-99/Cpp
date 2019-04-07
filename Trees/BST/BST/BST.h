//
//  BST.h
//  BST
//
//  Created by Adam Saher on 19/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.

//ADD TO YOUR CODE: perfectly balanced (left and right differ by at most one)
// compleste, height balanced(height differ by at most 1)

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
    void insert(const T&);
    void remove(const T&);
    std::ostream& level_order(std::ostream&, const Node<T>*) const;
    std::ostream& in_order(std::ostream&) const;
    std::ostream& in_order(std::ostream&, const Node<T>*) const;
    //    void iterative_insert(const T&);
private:
    bool node_exists(Node<T>*&, const T&) const;
    void destroy(Node<T>*&);
    void insert(Node<T>*&, const T&);
    void remove(Node<T>*&);
    Node<T>*& get_node(Node<T>*&, const T&);
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
bool BST<T>::exists(const T& value) {
    return node_exists(root_, value);
}


template <typename T>
void BST<T>::insert(const T &value) {
    insert(root_, value);
}


template <typename T>
void BST<T>::remove(const T & data) {
    remove(get_node(root_, data));
}


template <typename T>
Node<T>*& BST<T>::get_node(Node<T>*& current, const T& data) {
    if (!current)
        return current; //to go arround returning a nullptr by reference! 
    if (current->data_ == data)
        return current;
    if (data < current->data_)
        return get_node(current->left_, data);
    return get_node(current->right_, data);
        
}



template <typename T>
void BST<T>::remove(Node<T> *& node) {
    if (!node)
        return;
    
    if (!(node->right_ || node->left_)) {
        delete node;
        node = nullptr;
    }
    
    //We passed the previous condition, then at least one side exists
    else if (!node->right_) {
        node->data_ = node->left_->data_;
        delete node->left_;
        node->left_ = nullptr;
    }
    
    //We passed the previous condition, then node->right_ exists
    else if (!node->left_ || !node->right_->left_) {
        auto tmp = node->right_;
        node->data_ = node->right_->data_;
        node->right_ = node->right_->right_;
        delete tmp;
    }
    
    else {
        auto tmp = node->right_;
        auto parent_of_tmp = node;
        while (tmp->left_) {
            parent_of_tmp = tmp;
            tmp = tmp->left_;
        }
        node->data_ = tmp->data_;
        parent_of_tmp->left_ = tmp->right_;
        delete tmp;
    }
        
}


template <typename T>
std::ostream& BST<T>::level_order(std::ostream& os, const Node<T>* current) const {
    if (!current)
        return os << "|";
    
    std::queue<Node<T>*> q;
    q.push(root_);
    std::vector<Node<T>*> tmp_vector;
    
    do {
        for (auto node : tmp_vector)
            q.push(node);
        tmp_vector.clear();
        
        Node<T>* tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            os << tmp->data_ << ' ';
            if (tmp->left_)
                tmp_vector.push_back(tmp->left_);
            if (tmp->right_)
                tmp_vector.push_back(tmp->right_);
        }
        os << std::endl;
    }  while (!tmp_vector.empty());
    
    return os;
}


template <typename T>
std::ostream& BST<T>::in_order(std::ostream &os) const {
    in_order(os, root_);
    return os;
}


template <typename T>
std::ostream& BST<T>::in_order(std::ostream &os, const Node<T> * node) const {
    if (!node)
    return os << '\0';
    in_order(os, node->left_);
    os <<  " " << node->data_ << " ";
    in_order(os, node->right_);
    return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& bst) {
    bst.level_order(os, bst.root_);
    return os;
}


template <typename T>
bool BST<T>::node_exists(Node<T>*& node, const T & data) const {
    if (!node)
    return false;
    else if (node->data_ == data)
    return true;
    else if (data < node->data_)
    return node_exists(node->left_);
    else
    return node_exists(node->right_);
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
void BST<T>::insert(Node<T>*& node, const T& value) {
    if (!node)
    node = new Node<T>(value);
    else {
        if (value < node->data_)
        insert(node->left_, value);
        else if (value > node->data_)
        insert(node->right_, value);
    }
}


    
#endif /* BST_h */
