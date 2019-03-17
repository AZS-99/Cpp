#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include "Node.hpp"
#include "Const_iterator.hpp"
#include "Iterator.hpp"

namespace Container {
    template <typename T> class Const_iterator;
    
    template <typename T>
    class LinkedList{
        Node<T>* head_;
        Node<T>* tail_;
        size_t size_;
        friend Const_iterator<T>;
    public:
        LinkedList();
        ~LinkedList();
        void operator+=(T value);
        void push_front(const T&);
        void pop_front();
        void push_back(const T&);
        void pop_back(const T&);
        void reverseprint() const;
        std::ostream& print(std::ostream& os) const;
        Const_iterator<T> cbegin() const;
        Const_iterator<T> cend() const;
        Const_iterator<T> crend() const;
        Const_iterator<T> crbegin() const;
        Iterator<T> begin();
        Iterator<T> end();
        //REMEMBER WITH SENTINEL RETURN HEAD_->NXT AND TAIL!
        Iterator<T> begin() const;
        Iterator<T> end() const;
        
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
            node->prev_ = tail_;
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
    
    template <typename T>
    Const_iterator<T> LinkedList<T>::cbegin() const {
        return Const_iterator<T>(head_, this); //took me forever to figure out that this needs to be CONST LinkedList<T>* in the constructor.
    }
    
    
    
    
    
    template <typename T>
    Const_iterator<T> LinkedList<T>::cend() const { //handle the case of doubling back from cend
        return Const_iterator<T>(nullptr, this);
    }
    
    
    template <typename T>
    Const_iterator<T> LinkedList<T>::crbegin() const {
        return Const_iterator<T>(nullptr, this);
    }
    
    //Problem hers is that ++ uses nxt, not prev.
    template <typename T>
    Const_iterator<T> LinkedList<T>::crend() const {
        return Const_iterator<T>(tail_, this);
    }
    
    
    template <typename T>
    void LinkedList<T>::reverseprint() const {
        Node<T>* current = tail_;
        while(current) {
            std::cout << current->data_ << " --> ";
            current = current->prev_;
        }
    }
    
    
    template <typename T>
    Iterator<T> LinkedList<T>::begin() {
        return Iterator<T>(head_, this);
    }
    
    
    template <typename T>
    Iterator<T> LinkedList<T>::end() {
        return Iterator<T>(nullptr, this);
    }
    
    
    template <typename T>
    Iterator<T> LinkedList<T>::begin() const {
        return Iterator<T>(head_, this);
    }
    
    
    template <typename T>
    Iterator<T> LinkedList<T>::end() const {
        return Iterator<T>(this);
    }
    
    
}



#endif /* LinkedList_hpp */

