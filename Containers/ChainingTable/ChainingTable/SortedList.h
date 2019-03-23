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
    class iterator;       //Forward declaration
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
    std::ostream& display(std::ostream&) const;
    
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
    //Delete the passed node with all the ones that follow.
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
    for (auto it = begin(); it != end(); ++it)
        delete it.current_->prev_;
    delete tail_->prev_;
    delete tail_;
}


template <typename T>
SortedList<T>::SortedList(const SortedList<T>& src) {
    head_ = new Node<T>();
    tail_ = new Node<T>(T{}, nullptr, head_);
    head_->nxt_ = tail_;
    Node<T>* node_ptr;
    for (auto it = src.cbegin(); it != src.cend(); ++it) {
        node_ptr = new Node<T>(*it, tail_, tail_->prev_);
        tail_->prev_->nxt_ = node_ptr;
        tail_->prev_ = node_ptr;
    }
    size_ = src.size_;
}


template <typename T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& src) {
    if (this != &src) {
        auto it_this = begin();
        //if there is still a node in the lhs, overwrite its value; otherwise, create a new node
        //and append it to the lhs, creating a path for the one you need to copy.
        for (auto it_other = src.cbegin(); it_other != src.cend(); ++it_other) {
            *it_this = *it_other;
            if (!it_this.current_->nxt_)
                it_this.current_->nxt_ = new Node<T>(T{}, nullptr, it_this.current_);
            ++it_this;
        }
        //Mark the node which your iterator is wrapping as tail.
        tail_ = it_this.current_;
        //if the lhs is longer than the rhs, delete the rest of the nodes that come after tail_.
        if (tail_->nxt_) {
            trim(tail_->nxt_);
            tail_->nxt_ = nullptr;
        }
        size_ = src.size_;
    }
    return *this;
}


template <typename T>
SortedList<T>::SortedList(SortedList&& src) {
    size_ = src.size_;
    head_ = src.head_;
    tail_ = src.tail_;
    
    src.size_ = 0u;
    src.head_ = new Node<T>();
    src.tail_= new Node<T>(T{}, nullptr, src.head_);
    src.head_->nxt_ = src.tail_;
}


template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList<T>&& src) {
    std::swap(size_, src.size_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
    return *this;
}


//Delete the node wrapped by the passed iterator.
//Return: iterator to the next node that comes after the deleted one
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


//Erase all nodes starting from the one wrapped by the first parameter till the one wrapped by the second parameter (not included)
//Param first: iterator wrapping the first node to be deleted
//Param last: iterator wrapping the last node right after the last deleted node
template <typename T>
typename SortedList<T>::iterator SortedList<T>::erase(iterator first, iterator last) {
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


//Search for the first node holding the passed data
//Return: const_iterator wrapping the node holding the passed data
template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::search(const T& data) const {
    auto it = cbegin();
    while (*it < data && it != cend()) ++it;
    return (*it == data? it : cend());
}


//Get an iterator wrapping the first node holding the passed value
//Return: iterator
template <typename T>
typename SortedList<T>::iterator SortedList<T>::search(const T& data) {
    auto it = begin();
    while (it.current_->data_ < data && it != end()) ++it;
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


//Insert a node holding the passed value into the sortedlist.
//Return: iterator to the inserted node
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
std::ostream& SortedList<T>::display(std::ostream& os) const {
    for(auto it = cbegin(); it != cend(); ++it)
        os << *it << " --> ";
    return os << '|';
}


//Delete the passed node along with all its descendants
//Param node_ptr: A node of type T that you need to trim
template <typename T>
void SortedList<T>::trim(Node<T> * node_ptr) {
    if (node_ptr->nxt_)
        trim(node_ptr->nxt_);
    delete node_ptr;
}


//Default const_iterator constructor
template <typename T>
SortedList<T>::const_iterator::const_iterator() {
    const_iterator::current_ = nullptr;
}


//Const_iterator constructor wrapping the passed node
//Return: void
template <typename T>
SortedList<T>::const_iterator::const_iterator(Node<T>* node_ptr) {
    current_ = node_ptr;
}


//Increment operator for const_iterator
//Return: a const_iterator wrapping the node next to the one wrapped by the current iterator
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


template <typename T>
std::ostream& operator<<(std::ostream& os, SortedList<T> lst) {
    lst.display(os);
    return os;
}



#endif /* SortedList_hpp */
