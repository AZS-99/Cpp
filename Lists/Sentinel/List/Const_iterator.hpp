//
//  Const_iterator.hpp
//  List
//
//  Created by Adam Saher on 15/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Const_iterator_h
#define Const_iterator_h

template <typename T> class List;

template <typename T>
class Const_iterator {
    Node<T>* current_;
    friend List<T>;
protected:
    Const_iterator(Node<T>*);
public:
    Const_iterator& operator++();
    const T& operator*();
    bool operator!=(const Const_iterator&) const;
};


template <typename T>
Const_iterator<T>::Const_iterator(Node<T>* node) {
    current_ =  node;
}


template <typename T>
Const_iterator<T>& Const_iterator<T>::operator++() {
    if (current_->nxt_)
        current_ = current_->nxt_;
    return *this;
}


template <typename T>
const T& Const_iterator<T>::operator*() {
    return current_->data_;
}


template <typename T>
bool Const_iterator<T>::operator!=(const Const_iterator<T>& other) const {
    return this->current_ != other.current_;
}

#endif /* Const_iterator_h */
