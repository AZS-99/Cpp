//
//  Const_iterator.hpp
//  LinkedList
//
//  Created by Adam Saher on 01/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Const_iterator_h
#define Const_iterator_h

namespace Container {
    template <typename T>
    class LinkedList;
    
    template <typename T>
    class Const_iterator {
        Node<T>* current_;
        friend LinkedList<T>;
    protected:
        Const_iterator(Node<T>* current);
    public:
        Const_iterator();
        T operator*();
        Const_iterator operator++();     // ++x
        Const_iterator operator++(int);  // x++
        bool operator==(Const_iterator other) {
            return (current_ == other.current_);
        }
        
        bool operator!=(Const_iterator other) {
            return (current_ != other.current_);
        }
        
        
    };
    
    
    template <typename T>
    Const_iterator<T>::Const_iterator() {
        current_ = nullptr;
    }
    
    
    template <typename T>
    Const_iterator<T>::Const_iterator(Node<T>* head) {
        current_ = head;
    }
    
    
    template <typename T>
    Const_iterator<T> Const_iterator<T>::operator++(int ) {
        //Remember that x++ returns the old value
        Const_iterator old = *this;
        current_ = current_->nxt_;
        return old;
    }
    
    
    template <typename T>
    Const_iterator<T> Const_iterator<T>::operator++() {
        
        current_ = current_->nxt;
        return *this;
    }
    
    
    template <typename T>
    T Const_iterator<T>::operator*() {
        return current_->data_;
    }
    
}


#endif /* Const_iterator_h */
