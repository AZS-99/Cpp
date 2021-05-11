//
//  node.h
//  Node
//
//  Created by Adam Saher on 2021-04-04.
//

#ifndef node_h
#define node_h

#include <iostream>
#include <cmath>

template <typename T>
struct Node {
    T value;
    Node<T>* nxt;
public:
    Node(T = T{}, Node<T>* = nullptr);
    Node(const Node<T>&);
    Node<T>& operator=(const Node<T>&);
    Node<T>& operator+(const Node<T>&) const;
    void append(const T&);
    void prepend(const T&);
    
    template <typename U> //Not a member, so T (applied on class) isn't visible
    friend std::ostream& operator<<(std::ostream&, const Node<U>&);
};


template <typename T>
Node<T>::Node(T value, Node* nxt) : value(value), nxt(nxt) {}


template <typename T>
Node<T>::Node(const Node<T>& other) {
    this->value = other.value;
    auto current = this;
    auto other_current = &other;
    while (other_current->nxt) {
        other_current = other_current->nxt;
        current->nxt = new Node<T>(other_current->value);
        current = current->nxt;
    }
}


template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& other) {
    std::cout << "in" << std::endl;
}


template <typename T>
void Node<T>::append(const T& value) {
    if (!nxt)
        nxt = new Node<T>(value);
    else
        nxt->append(value);
}


template <typename T>
void Node<T>::prepend(const T& value) {
    auto node = new Node(value, nxt);
    nxt = node;
    std::swap(this->value, node->value);
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    if (!node.nxt)
        return os << node.value << "-->|";
    else
        return os << node.value << "-->" << *node.nxt;
}


/*
 Add two lists. Each node contains a single digit. Assume the order is reversed (units, then tens, hundreds ...)
 Example: [1, 4] + [1, 9] = [2, 3, 1] --->  (41 + 91 = 132)
 */
Node<int>* add_two_numbers(const Node<int>* node1, const Node<int>* node2) {
    auto current1 = node1;
    auto current2 = node2;
    auto node = new Node<int>((current1->value + current2->value) % 10);
    auto current = node;
    unsigned carry = (current1->value + current2->value) / 10;
    
    while (current1->nxt && current2->nxt) {
        current1 = current1->nxt;
        current2 = current2->nxt;
        current->nxt = new Node<int>((current1->value + current2->value + carry) % 10);
        current = current->nxt;
        carry = (current1->value + current2->value + carry) / 10;
    }
    
    auto current3 = current1->nxt? current1 : current2;
    while (current3->nxt) {
        current3 = current3->nxt;
        current->nxt = new Node<int>((current3->value + carry) % 10);
        current = current->nxt;
        carry = (current1->value + carry) / 10;
    }
    
    if (carry)
        current->nxt = new Node<int>(carry);
    return node;
}


//template <typename T>
//Node<T>* transfer(Node<T>* node, const T& value) {
//    auto raw_value = node->value + value;
//    node->value = raw_value % 10;
//    if (raw_value/10) {
//        if (!node->nxt)
//            node->nxt = new Node<T>(raw_value/10);
//        else
//            transfer(node->nxt, raw_value/10);
//    }
//    return node;
//
//}


//template <typename T>
//Node<T>* add_two_numbers(const Node<T>* node1, const Node<T>* node2) {
//    if (!node1 != !node2) {
//        auto original = node1? node1 : node2;
//        auto node = new Node<T>(original->value);
//        auto current = node;
//        while(original->nxt) {
//            original = original->nxt;
//            current->nxt = new Node<T>(original->value);
//            current = current->nxt;
//        }
//        return node;
//
//    } else {
//        auto second = add_two_numbers(node1->nxt, node2->nxt);
//        auto value = node1->value + node2->value;
//        auto node = new Node<T>(value % 10);
//        if (value/10)
//            transfer(second, value/10);
//        node->nxt = second;
//        return node;
//    }
//}






#endif /* node_h */
