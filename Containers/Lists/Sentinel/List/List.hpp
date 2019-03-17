//
//  List.hpp
//  List
//
//  Created by Adam Saher on 31/01/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef List_h
#define List_h
#include <string>
#include "Node.hpp"
#include "Const_iterator.hpp"

template <typename T>
class List {
    Node<T>* head_;
    Node<T>* tail_;
    size_t size_;
public:
    List();
    void push_front(T data);
    void pop_front();
    void push_back(T data);
    void pop_back(T data);
    Const_iterator<T> cbegin() const;
    Const_iterator<T> cend() const;
    std::ostream& print(std::ostream&) const;
};


template <typename T>
List<T>::List() {
    head_ = new Node<T>();
    tail_ = new Node<T>();
    head_->nxt_ = tail_;
    tail_->prev_ = head_;
    size_ = 0u;
}


template <typename T>
void List<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data, head_->nxt, head_);
    head_->nxt = node;
    node->nxt_->prev_ = node;
    ++size_;
}


template <typename T>
void List<T>::pop_front() {
    if (size_ == 0)
        return;
    Node<T>* rm = head_->nxt_;
    head_->nxt_ = rm->nxt_;
    rm->nxt_->prev_ = head_;
    delete rm;
    --size_;
}


template <typename T>
void List<T>::push_back(T data) {
    Node<T>* node = new Node<T>(data, tail_, tail_->prev_);
    tail_->prev_ = node;
    node->prev_->nxt_ = node;
    ++size_;
}


template <typename T>
void List<T>::pop_back(T data) {
    if (size_ > 0) {
        Node<T> tmp = tail_->prev_;
        tail_->prev_ = tmp->prev_;
        tmp->prev_->nxt_ = tail_;
        delete tmp;
    }
}


template <typename T>
std::ostream& List<T>::print(std::ostream& os) const {
    Node<T>* current = head_->nxt_;
    while (current != tail_) {
        os << current->data_ << " --> ";
        current = current->nxt_;
    }
    
    return os << '|';
}


template <typename T>
Const_iterator<T> List<T>::cbegin() const {
    return Const_iterator<T>(head_->nxt_);
}


template <typename T>
Const_iterator<T> List<T>::cend() const {
    return Const_iterator<T>(tail_);
}


template <typename T>
std::ostream& operator<<(std::ostream& os, List<T>& linked_lst) {
    linked_lst.print(os);
    return os;
}
#endif /* Sentinel_h */
