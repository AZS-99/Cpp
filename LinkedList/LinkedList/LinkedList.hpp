#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include "Node.hpp"
#include "Const_iterator.hpp"

namespace Container {
    template <typename T>
    class LinkedList{
        Node<T>* head_;
        Node<T>* tail_;
        size_t size_;
    public:
        LinkedList();
        ~LinkedList();
        void operator+=(T value);
        void push_front(const T&);
        void pop_front();
        void push_back(const T&);
        void pop_back(const T&);
        std::ostream& print(std::ostream& os) const;
        Const_iterator<T> cbegin() const {
            return Const_iterator<T>(head_);
        }
        Const_iterator<T> cend() const {
            return Const_iterator<T>(nullptr);
        }
    };
    
    
    template <typename T>
    LinkedList<T>::LinkedList(){
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
    
    
    template <typename T>
    LinkedList<T>::~LinkedList<T>() {
        
    }
    
    
    template <typename T>
    void LinkedList<T>::operator+=(T value){
        Node<T>* node = new Node<T>(value);
        if (!head_)
            head_ = tail_ = node;
        else{
            tail_->nxt_ = node;
            tail_ = tail_->nxt_;
        }
    }
    
    
    template <typename T>
    void LinkedList<T>::push_front(const T& data) {
        Node<T>* node = new Node<T>(data, head_);
        if (head_) {
            head_->prev_ = node;
        }
        else
            tail_ = node;
        head_ = node;
    }
    
    
    template <typename T>
    void LinkedList<T>::pop_front() {
        if (head_) {
            if (head_ != tail_) {
                Node<T>* tmp = head_;
                head_ = head_->nxt_;
                head_->prev_ = nullptr;
                delete tmp;
            }
            else {
                delete head_;
                head_ = tail_ = nullptr;
            }
        }
    }
    
    
    template <typename T>
    void LinkedList<T>::push_back(const T& data) {
        Node<T>* node = new Node<T>(data);
        if (tail_) {
            tail_->nxt_ = node;
            node->prev_ = tail_;
            tail_ = tail_->nxt;
        }
        else
            head_ = tail_ = node;
    }
    
    
    template <typename T>
    void LinkedList<T>::pop_back(const T& data) {
        tail_ = tail_->prev_;
        delete tail_->nxt_;
    }
    
    
    template <typename T>
    std::ostream& LinkedList<T>::print(std::ostream& os) const{
        Node<T>* current = head_;
        while(current){
            os << current->data_ << " --> ";
            current = current->nxt_;
        }
        os << "|" << std::endl;
        return os;
    }
    
    
    template <typename T>
    std::ostream& operator<<(std::ostream& os, LinkedList<T>& linked){
        linked.print(os);
        return os;
    }
}



#endif /* LinkedList_hpp */

