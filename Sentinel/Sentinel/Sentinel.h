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

template <typename T>
class Sentinel {
    struct Node {
        T data_;
        Node* nxt_;
        Node* prev_;
        Node(const T& data = T{}, Node* nxt = nullptr, Node* prev = nullptr) {
            data_ = data;
            nxt_ = nxt;
            prev_ = prev;
        }
    };
    Node* head_;
    Node* tail_;
    size_t size_;
public:
    Sentinel();
    void push_front(T data);
    void pop_front();
};


template <typename T>
Sentinel<T>::Sentinel() {
    head_ = new Node();
    tail_ = new Node();
    head_->nxt_ = tail_;
    tail_->prev_ = head_;
    size_ = 0;
}

template <typename T>
void Sentinel<T>::push_front(T data) {
    Node* node = new Node(data, head_->nxt, head_);
    head_->nxt = node;
    node->nxt_->prev_ = node;
    size_++;
}


template <typename T>
void Sentinel<T>::pop_front() {
    if (size_ == 0)
        throw std::string("Deleting from empty list!");
    Node* rm = head_->nxt_;
    head_->nxt_ = rm->nxt_;
    rm->nxt_->prev_ = head_;
    delete rm;
    size_--;
}

#endif /* Sentinel_h */
