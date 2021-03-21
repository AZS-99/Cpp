//
//  linkedlist.h
//  3-LinkedList
//
//  Created by Adam Saher on 2021-03-18.
//

#ifndef list_h
#define list_h

#include <iostream>
#include "node.h"
#include "const_iterator.h"

template <typename T> class const_iterator;

template <typename T>
class List {
    Node<T>* head;
    Node<T>* tail;
    unsigned length;
public:
    List();
    bool empty() const;
    T& back() const;
    T& front() const;
    unsigned size() const;
    void pop_front();
    void pop_back();
    void push_back(const T&);
    void push_front(const T&);
    const_iterator<T> cbegin() const;
    const_iterator<T> cend() const;
    const_iterator<T> crbegin() const;
    
    
    std::ostream& print(std::ostream&) const;
    friend const_iterator<T>;
};


template <typename T>
List<T>::List() {
    head = tail = nullptr;
    length = 0u;
}


template <typename T>
bool List<T>::empty() const {
    return !head;
}


template <typename T>
const_iterator<T> List<T>::cbegin() const {
    return const_iterator<T>(head, this);  //Since the fn is const, List MUST be a const as an attribute of iterator
}


template <typename T>
const_iterator<T> List<T>::cend() const {
    return const_iterator<T>(nullptr, this);
}


template <typename T>
const_iterator<T> List<T>::crbegin() const {
    return const_iterator<T>(tail, this);
}


template <typename T>
T& List<T>::back() const {
    return tail->value;
}


template <typename T>
T& List<T>::front() const {
    return head->value;
}


template <typename T>
unsigned List<T>::size() const {
    return length;
}


// &Node instead of (new Node) would be destroyed as soon as the void fn terminates.
template <typename T>
void List<T>::push_back(const T& value) {
    if (!head)
        head = tail = new Node<T>(value);
    else {
        tail->nxt = new Node<T>(value, nullptr, tail);
        tail = tail->nxt;
    }
    ++length;
}


template <typename T>
void List<T>::push_front(const T& value) {
    if (!head) {
        head = tail = new Node(value);
    } else {
        auto node = new Node(value, head);
        head->prev = node;
        head = node;
    }
    ++length;
}


template <typename T>
void List<T>::pop_back() {
    if (head) {
        if (tail == head) {
            delete tail;
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->nxt;
            tail->nxt = nullptr;
        }
        --length;
    }
}


template <typename T>
void List<T>::pop_front() {
    if (head) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->nxt;
            delete head->prev;
            head->prev = nullptr;
        }
        --length;
    }
}


template <typename T>
std::ostream& List<T>::print(std::ostream& os) const {
    auto current = head;
    while (current) {
        os << current->value << "-->";
        current = current->nxt;
    }
    return os << '|';
}


#endif /* linkedlist_h */
