//
//  SortedList.hpp
//  SortedList
//
//  Created by Adam Saher on 16/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef SortedList_hpp
#define SortedList_hpp

#include <iostream>
#include "Node.h"


template <typename T>
class SortedList {
    Node<T>* head_;
    Node<T>* tail_;
    unsigned size_;
    
public:
    class const_iterator; //Forward declaration
    class iterator;
    SortedList();
    ~SortedList();
    SortedList(const SortedList& rhs);
    SortedList& operator=(const SortedList& rhs);
    SortedList(SortedList&& rhs);
    SortedList& operator=(SortedList&& rhs);
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator insert(const T& data);
    iterator search(const T& data);
    const_iterator search(const T& data) const;
    iterator erase(iterator it);
    iterator erase(iterator first, iterator last);
    bool empty() const;
    int size() const;
    
    class const_iterator {
        Node<T>* current_;
        friend SortedList;
    protected:
        const_iterator(Node<T>*);
    public:
        const_iterator();
        const_iterator operator++();
        const_iterator operator++(int);
        const_iterator operator--();
        const_iterator operator--(int);
        bool operator==(const_iterator rhs) const;
        bool operator!=(const_iterator rhs) const;
        const T& operator*() const;
    };
    
    class iterator : public const_iterator {
        
        iterator(Node<T>*);
        friend SortedList<T>;
    public:
        iterator();
        iterator operator--();
        iterator operator--(int);
        T& operator*() const;
    };
private:
    void trim(Node<T>*);
};


template <typename T>
SortedList<T>::SortedList() {
    head_ = new Node<T>();
    tail_ = new Node<T>(T{}, nullptr, head_);
    head_->nxt_ = tail_;
    size_ = 0u;
}


template <typename T>
SortedList<T>::~SortedList<T>() {
    if (this->head_ && this->tail_) {
        auto it = const_iterator(tail_->prev_);
        while (it.current_ != head_) {
            delete it.current_->nxt_;
            --it;
        }
        delete head_;
    }
}


template <typename T>
SortedList<T>::SortedList(const SortedList<T>& other) {
    *this = SortedList();
    Node<T>* node_ptr;
    for (auto it = other.cbegin(); it != other.cend(); ++it) {
        node_ptr = new Node<T>(*it, tail_, tail_->prev_);
        tail_->prev_->nxt_ = node_ptr;
        tail_->prev_ = node_ptr;
    }
    size_ = other.size_;
}


template <typename T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& other) {
    if (this != &other) {
        auto it_this = begin();
        for (auto it_other = other.cbegin(); it_other != other.cend(); ++it_other) {
            it_this.current_->data_ = it_other.current_->data_;
            if (!it_this.current_->nxt_)
                it_this.current_->nxt_ = new Node<T>(T{}, nullptr, it_this.current_);
            ++it_this;
        }
        tail_ = it_this.current_;
        if (tail_->nxt_) {
            trim(tail_->nxt_);
            tail_->nxt_ = nullptr;
        }
        size_ = other.size_;
    }
    return *this;
}


template <typename T>
SortedList<T>::SortedList(SortedList&& src) {
    size_ = src.size_;
    head_ = src.head_;
    tail_ = src.tail_;
    
    src.size_ = 0;
    src.head_ = new Node<T>();
    src.tail_= new Node<T>();
    src.head_->nxt_ = src.tail_;
    src.tail_->prev_ = src.head_;
}


template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList<T>&& src) {
    std::swap(size_, src.size_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
    return *this;
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::erase(iterator it) {
    if (it.current_ != tail_) {
        Node<T>* tmp = it.current_;
        tmp->nxt_->prev_ = tmp->prev_;
        tmp->prev_->nxt_ = tmp->nxt_;
        ++it;
        delete tmp;
        --size_;
    }
    return it;
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::erase(iterator first, iterator last) { //What if last were ahead of first?!
    Node<T>* tmp = first.current_->prev_;
    for (auto it = ++first; it != last; ++it)
        delete it.current_->prev_;
    delete last.current_->prev_;
    tmp->nxt_ = last.current_;
    last.current_->prev_ = tmp;
    
    return last;
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::cbegin() const {
    return const_iterator(head_->nxt_);
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::cend() const {
    return const_iterator(tail_);
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::begin() {
    return SortedList<T>::iterator(head_->nxt_);
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::end() {
    return SortedList<T>::iterator(tail_);
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::search(const T& data) const {
    auto it = cbegin();
    while (it.current_->data_ < data && it != cend())
        ++it;
    return (it.current_->data_ == data? it : cend());
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::search(const T& data) {
    auto it = begin();
    while (it.current_->data_ < data && it != end())
        ++it;
    return (it.current_->data_ == data? it : end());
}


template <typename T>
bool SortedList<T>::empty() const {
    return size_ == 0;
}


template <typename T>
int SortedList<T>::size() const {
    return size_;
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::insert(const T &data) {
    Node<T>* node_ptr;
    auto it = begin();
    while(it.current_ != tail_) {
        if (data < it.current_->data_) {
            node_ptr = new Node<T>(data, it.current_, it.current_->prev_);
            node_ptr->prev_->nxt_ = node_ptr;
            it.current_->prev_ = node_ptr;
            ++size_;
            return --it;
        }
        ++it;
    }
    node_ptr = new Node<T>(data, tail_, tail_->prev_);
    tail_->prev_ = node_ptr;
    node_ptr->prev_->nxt_ = node_ptr;
    ++size_;
    return --it;
}


template <typename T>
void SortedList<T>::trim(Node<T> * node_ptr) {
    if (node_ptr->nxt_)
        trim(node_ptr->nxt_);
    std::cout << "value: " << node_ptr->data_ << std::endl;
    delete node_ptr;
}


template <typename T>
SortedList<T>::const_iterator::const_iterator() {
    const_iterator::current_ = nullptr;
}


template <typename T>
SortedList<T>::const_iterator::const_iterator(Node<T>* node_ptr) {
    current_ = node_ptr;
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++() {
    if (current_->nxt_)
        current_ = current_->nxt_;
    return *this;
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++(int) {
    auto old_iterator = *this;
    if (current_->nxt_)
        current_ = current_->nxt_;
    return old_iterator;
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator--() {
    if (current_->prev_)
        current_ = current_->prev_;
    return *this;
}


template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator--(int) {
    auto old_iterator = *this;
    if (current_->prev_)
        current_ = current_->prev_;
    return old_iterator;
}


template <typename T>
bool SortedList<T>::const_iterator::operator==(SortedList<T>::const_iterator rhs) const {
    return current_ == rhs.current_;
}


template <typename T>
bool SortedList<T>::const_iterator::operator!=(const_iterator rhs) const {
    return current_ != rhs.current_;
}


template <typename T>
const T& SortedList<T>::const_iterator::operator*() const {
    return current_->data_;
}


template <typename T>
SortedList<T>::iterator::iterator(Node<T>* node_ptr) : SortedList<T>::const_iterator(node_ptr){}


template <typename T>
SortedList<T>::iterator::iterator() {
    this->current_ = nullptr;
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::iterator::operator--() {
    if (this->current_->prev_)
        this->current_ = this->current_->prev_;
    return *this;
}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::iterator::operator--(int) {
    auto old = *this;
    if (this->current_->prev_)
        this->current_ = this->current_->prev_;
    return old;
}


template <typename T>
T& SortedList<T>::iterator::operator*() const {
    return this->current_->data_;
}
#endif /* SortedList_hpp */
