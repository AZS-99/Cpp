//
//  Sentinel.h
//  Sentinel
//
//  Created by Adam Saher on 31/01/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Sentinel_h
#define Sentinel_h
#include <string>
#include "Node.hpp"


template <typename T>
class Sentinel {
    Node<T>* head_;
    Node<T>* tail_;
    size_t size_;
public:
    Sentinel();
    void push_front(T data);
    void pop_front();
    void push_back(T data);
    void pop_back(T data);
    std::ostream& print(std::ostream&) const;
};


template <typename T>
Sentinel<T>::Sentinel() {
    head_ = new Node<T>();
    tail_ = new Node<T>();
    head_->nxt_ = tail_;
    tail_->prev_ = head_;
    size_ = 0;
}


template <typename T>
void Sentinel<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data, head_->nxt, head_);
    head_->nxt = node;
    node->nxt_->prev_ = node;
    ++size_;
}


template <typename T>
void Sentinel<T>::pop_front() {
    if (size_ == 0)
        throw std::string("Deleting from empty list!");
    Node<T>* rm = head_->nxt_;
    head_->nxt_ = rm->nxt_;
    rm->nxt_->prev_ = head_;
    delete rm;
    --size_;
}


template <typename T>
void Sentinel<T>::push_back(T data) {
    Node<T>* node = new Node<T>(data, tail_, tail_->prev_);
    tail_->prev_ = node;
    node->prev_->nxt_ = node;
    ++size_;
}


template <typename T>
void Sentinel<T>::pop_back(T data) {
    if (size_ > 0) {
        Node<T> tmp = tail_->prev_;
        tail_->prev_ = tmp->prev_;
        tmp->prev_->nxt_ = tail_;
        delete tmp;
    }
}


template <typename T>
std::ostream& Sentinel<T>::print(std::ostream& os) const {
    Node<T>* current = head_->nxt_;
    while (current != tail_) {
        os << current->data_ << " --> ";
        current = current->nxt_;
    }
    
    return os << '|';
}


template <typename T>
std::ostream& operator<<(std::ostream& os, Sentinel<T>& linked_lst) {
    linked_lst.print(os);
    return os;
}
#endif /* Sentinel_h */
