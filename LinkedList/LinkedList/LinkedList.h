#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
using namespace std;

namespace DataStructure{
    template <typename T>
    struct Node{
        T value;
        Node<T>* nxt;
        
    public:
        Node(T value);
        void print() const;
        void operator+=(T value);
    };
    
    
    template <typename T>
    Node<T>::Node(T value){
        this->value = value;
        this->nxt = nullptr;
    }
    
    template <typename T>
    void Node<T>::operator+=(T value){
        Node<T>* node = new Node(value);
        Node<T>* current = this;
        while(current->nxt)
            current = current->nxt;
        current->nxt = node;
    }
    
    
    
    template <typename T>
    void Node<T>::print() const{
        cout << value << "-->" << nxt->value << endl;
    }
    
    
    
    /**************************************/
    
    
    template <typename T>
    class LinkedList{
        Node<T>* head;
        Node<T>* tail;
        
    public:
        LinkedList();
        void operator+=(T value);
        void print() const;
        ostream& display(ostream& os) const;
    };
    
    template <typename T>
    LinkedList<T>::LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    
    template <typename T>
    void LinkedList<T>::operator+=(T value){
        Node<T>* node = new Node<T>(value);
        if (!head)
            head = tail = node;
        else{
            tail->nxt = node;
            tail = tail->nxt;
        }
    }
    
    template <typename T>
    void LinkedList<T>::print() const{
        Node<T>* current = head;
        while(current){
            cout << current->value << " --> ";
            current = current->nxt;
        }
        cout << "|" << endl;
    }
    
    template <typename T>
    ostream& LinkedList<T>::display(ostream& os) const{
        Node<T>* current = head;
        while(current){
            os << current->value << " --> ";
            current = current->nxt;
        }
        os << "|" << endl;
        return os;
    }
    
    template <typename T>
    ostream& operator<<(ostream& os, LinkedList<T>& linked){
        linked.display(os);
        return os;
    }
}




#endif /* LinkedList_hpp */

