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
    Const_iterator(const Const_iterator&);
    Const_iterator& operator=(const Const_iterator&);
    Const_iterator(Const_iterator&&);
    Const_iterator<T>& operator=(Const_iterator&&);
    Const_iterator operator++(int);
    const T& operator*();
    bool operator!=(const Const_iterator&) const;
};


template <typename T>
Const_iterator<T>::Const_iterator(Node<T>* node) {
    current_ =  node;
}


template <typename T>
Const_iterator<T>::Const_iterator(const Const_iterator& src) {
    std::cout << "copy_constructor" << std::endl;
    current_ = src.current_;
}


template <typename T>
Const_iterator<T>& Const_iterator<T>::operator=(const Const_iterator& src) {
    std::cout << "copy_assignment" << std::endl;
    current_ = src.current_;
    return *this;
}


template <typename T>
Const_iterator<T>::Const_iterator(Const_iterator<T>&& src) {
    std::cout << "move_constructor" << std::endl;
    current_ = src.current_;
}


template <typename T>
Const_iterator<T>& Const_iterator<T>::operator=(Const_iterator&& src) {
    std::cout << "move_assignment" << std::endl;
    std::swap(current_, src.current_);
    return *this;
}


template <typename T>
Const_iterator<T>& Const_iterator<T>::operator++() {
    if (current_->nxt_)
        current_ = current_->nxt_;
    return *this;
}

template <typename T>
Const_iterator<T> Const_iterator<T>::operator++(int) {
    auto old = *this;
    if (current_->nxt_)
        current_ = current_->nxt_;
    return old;
}


template <typename T>
const T& Const_iterator<T>::operator*() {
    return current_->data_; //in case of head/tail, data_ = T{} 
}


template <typename T>
bool Const_iterator<T>::operator!=(const Const_iterator<T>& other) const {
    return this->current_ != other.current_;
}

#endif /* Const_iterator_h */
