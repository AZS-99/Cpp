//
//  bst.h
//  BST
//
//  Created by Adam Saher on 2021-04-11.
//

#ifndef bst_h
#define bst_h

#include <list>
#include <stack>
#include <vector>
#include "node.h"





template <typename T>
class BST {
    BSTnode<T>* root;
    unsigned size_;
    
public:
    BST(BSTnode<T>* = nullptr);
    std::vector<T> sort() const;
    unsigned count() const;
    unsigned height() const;
    unsigned size() const;
    void insert(const T&);
    void remove(const T&);
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const BST<U>&);
private:
    std::tuple<BSTnode<T>*, BSTnode<T>*> find(const T&) const;
    std::ostream& print(std::ostream&) const;
    unsigned grandchild_ordinal(BSTnode<T>*) const;
};


template <typename T>
unsigned BST<T>::height() const {
    return root->furthest_grandchild_ordinal();
}

template <typename T>
unsigned BST<T>::size() const {
    return size_;
}



template <typename T>
BST<T>::BST(BSTnode<T>* root) : root(root) {};


template <typename T>
void BST<T>::insert(const T& value) {
    auto node = new BSTnode<T>(value);
    if (!root)
        root = node;
    else {
        auto current = root;
        while ((value > current->value && current->right) || (value < current->value && current->left)) {
            while (value < current->value && current->left)
                current = current->left;
            while (value > current->value && current->right)
                current = current->right;
        }
        if (value == current->value) return;
        
        if (value < current->value)
            current->left = node;
        else
            current->right = node;
    }
    ++size_;
}


template <typename T>
std::tuple<BSTnode<T>*, BSTnode<T>*> BST<T>::find(const T& value) const {
    if (!root)
        return std::make_tuple(nullptr, nullptr);
    if (root->value == value)
        return std::make_tuple(root, nullptr);
    
    auto parent = root;
    auto current = value < root->value? root->left : root->right;
    
    while (current && current->value != value) {
        parent = current;
        current = value < current->value? current->left : current->right;
    }
    return current? std::make_tuple(current, parent) : std::make_tuple(nullptr, nullptr);
}


//level-order
template <typename T>
std::ostream& BST<T>::print(std::ostream& os) const {
    std::list<BSTnode<T>*> parents, children;
    parents.push_back(root);
    
    while (!parents.empty()) {
        for (auto& element : parents) {
            os << element->value << ' ';
            if (element->left)
                children.push_back(element->left);
            if (element->right)
                children.push_back(element->right);
        }
        os << std::endl;
        parents.clear();
        children.swap(parents);
    }
    return os;
}


//In-Order
template <typename T>
std::vector<T> BST<T>::sort() const {
    auto sorted = std::vector<T>();
    std::stack<BSTnode<T>*> node_stack;
    
    auto current = root;
    while (current) {
        node_stack.push(current);
        current = current->left;
    }
    
    while (!node_stack.empty()) {
        current = node_stack.top();
        sorted.push_back(current->value);
        node_stack.pop();
        if (current->right)
            node_stack.push(current->right);
    }
    return sorted;
}



template <typename T>
void BST<T>::remove(const T& value) {
    auto [current, parent] = find(value);
    if (current) {
        if (!(current->right || current->left)) {
            if (current == parent->left)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete current;
        } else if (!current->right != !current->left) {
            if (current == parent->left)
                parent->left = current->right? current->right : current->left;
            else
                parent->right = current->right? current->right : current->left;
            delete current;
        } else {
            auto surrogate_parent = current;
            auto surrogate = current->left;
            while (surrogate->right) {
                surrogate_parent = surrogate;
                surrogate = surrogate->right;
            }
            current->value = surrogate->value;
            delete surrogate;
            if (current == surrogate_parent)
                current->left = nullptr;
            else
                surrogate_parent->right = nullptr;
        }
    }
}


// operator<< is a friend of BST, not BSTnode, so it can't access the root->value directly, and needs print() method.
template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& bst) {
    return bst.print(os);
}

#endif /* bst_h */
