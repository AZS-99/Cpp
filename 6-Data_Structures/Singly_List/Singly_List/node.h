//
//  node.h
//  Singly_List
//
//  Created by Adam Saher on 2021-04-29.
//

#ifndef node_h
#define node_h

#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
public:
    Node(const T& = T{}, Node<T>* = nullptr);
    Node(const Node<T>&);
    Node(Node<T>&&);
    Node& operator=(const Node&);
    Node& operator=(Node&&);
    bool empty() const;
    bool insert_after(const T&, const T&);
    T& front();
    void push_front(const T&);
    void pop_front();
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Node<U>&);
private:
    Node<T>* find(const T&);
};


template <typename T>
Node<T>::Node(const T& value, Node<T>* next) : value (value), next(next) {}


template <typename T>
Node<T>::Node(const Node& src) {
    
}


template <typename T>
Node<T>& Node<T>::operator=(Node&& src) {
    std::swap(value, src.value);
    std::swap(next, src.next);
}


template <typename T>
Node<T>& Node<T>::operator=(const Node& src) {
    value = src.value;
    if (next) {
        delete next;
        next = new Node<T>(*src.next);
    }
    return *this;
}


template <typename T>
Node<T>::Node(Node<T>&& src) {
    value = src.value;
    next = src.next;
    src.next = nullptr;
}


template <typename T>
bool Node<T>::empty() const {
    return !this;
}


template <typename T>
void Node<T>::push_front(const T& value) {
    auto node = new Node(value, this->next);
    this->next = node;
    std::swap(this->value, node->value);
}


template <typename T>
T& Node<T>::front() {
    return value;
}


template <typename T>
bool Node<T>::insert_after(const T& value, const T& new_value) {
    auto node = find(value);
    if (node) {
        auto new_node = new Node(new_value, node->next);
        node->next = new_node;
        return true;
    }
    return false;
}


template <typename T>
Node<T>* Node<T>::find(const T& value) {
    if (this->value == value)
        return this;
    return next? next->find(value) : nullptr;
}


template <typename T>
void Node<T>::pop_front() {
    if (next) {
        value = next->value;
        auto tmp = next;
        next = next->next;
        delete tmp;
    }
}


/*
 Add two lists. Each node contains a single digit. Assume the order is reversed (units, then tens, hundreds ...)
 Example: [1, 4] + [1, 9] returns [2, 3, 1]  ( first is 41 + second is 91 --> yields 132)
 */
Node<int>* add_two_numbers(const Node<int>* node1, const Node<int>* node2) {
    auto current1 = node1;
    auto current2 = node2;
    auto node = new Node<int>((current1->value + current2->value) % 10);
    auto current = node;
    unsigned carry = (current1->value + current2->value) / 10;
    
    while (current1->next && current2->next) {
        current1 = current1->next;
        current2 = current2->next;
        current->next = new Node<int>((current1->value + current2->value + carry) % 10);
        current = current->next;
        carry = (current1->value + current2->value + carry) / 10;
    }
    
    auto current3 = current1->next? current1 : current2;
    while (current3->next) {
        current3 = current3->next;
        current->next = new Node<int>((current3->value + carry) % 10);
        current = current->next;
        carry = (current1->value + carry) / 10;
    }
    
    if (carry)
        current->next = new Node<int>(carry);
    return node;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    auto current = &node;
    while (current) {
        os << current->value << "->";
        current = current->next;
    }
    return os << '|';
}


#endif /* node_h */
