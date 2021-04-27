//
//  BST.h
//  BST
//
//  Created by Adam Saher on 2021-04-25.
//

#ifndef BST_h
#define BST_h

#include <cmath>
#include <queue>

template <typename T>
class Node {
    T value;
    Node<T>* left;
    Node<T>* right;
public:
    Node(const T& = T{}, Node<T>* = nullptr, Node<T>* = nullptr);
    bool insert(const T&);
    unsigned depth() const;
    unsigned height() const;
    unsigned size() const;
    void remove(const T&);
    std::ostream& print(std::ostream&) const;
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Node<U>&);
private:
    std::ostream& print_level(std::ostream& os, const unsigned&) const;
    std::tuple<Node<T>*, Node<T>*> find(const T&); // can't be a const fn because it returns 'this' pointer
};


template <typename T>
Node<T>::Node(const T& value, Node<T>* left, Node<T>* right) : value(value), left(left), right(right) {}


template <typename T>
bool Node<T>::insert(const T& val) {
    if (val < value) {
        if (!left) {
            left = new Node<T>(val);
            return true;
        }
        return left->insert(val);
    }
    if (val > value) {
        if (!right) {
            right = new Node<T>(val);
            return true;
        }
        return right->insert(val);
    }
    return false;
}


template <typename T>
unsigned Node<T>::height() const {
    if (!this)
        return 0;
    return std::max(left->height(), right->height()) + 1;
}


template <typename T>
unsigned Node<T>::size() const {
    if (!this)
        return 0;
    return left->size() + right->size() + 1;
}


template <typename T>
std::ostream& Node<T>::print_level(std::ostream& os, const unsigned& level) const {
    if (!this)
        return os;
    if (level == 0)
        return os << value << ' ';
    left->print_level(os, level - 1);
    right->print_level(os, level - 1);
    return os;
}


template <typename T>
std::ostream& Node<T>::print(std::ostream& os) const {
    for (auto i = 0u; i < height(); ++i) {
        print_level(os, i);
        std::cout << std::endl;
    }
    return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    return node.print(os);
}



template <typename T>
std::tuple<Node<T>*, Node<T>*> Node<T>::find(const T& val)  {
    if (!this) //value doesn't exist
        return std::tuple<Node<T>*, Node<T>*> (nullptr, nullptr);
    else if (val == value) //value is the root
        return std::tuple<Node<T>*, Node<T>*>(nullptr, this);
    else if (val  == left->value)
        return std::make_tuple(this, left);
    else if (val == right->value)
        return std::make_tuple(this, right);
    else if (val < value)
        return left->find(val);
    else
        return right->find(val);
}

    
#endif /* BST_h */
