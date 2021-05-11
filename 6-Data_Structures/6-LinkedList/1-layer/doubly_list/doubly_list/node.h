//
//  Node.h
//  doubly_list
//
//  Created by Adam Saher on 2021-04-29.
//

#ifndef Node_h
#define Node_h

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(const T& = T{}, Node<T>* = nullptr, Node<T>* = nullptr);
    Node(const Node&);
    Node(Node&&);
    Node& operator=(const Node&);
    void append(const T&);
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Node<U>&);
    
};


template <typename T>
Node<T>::Node(const T& value, Node<T>* next, Node<T>* prev) : value(value), next(next), prev(prev) {}


template <typename T>
Node<T>::Node(const Node& src) {
    if (!src.next) {
        value = src.value;
        next = prev = nullptr;
    } else {
        auto node = new Node(*src.next);
        node->prev = this;
        this->next = node;
        value = src.value;
    }
}


template <typename T>
Node<T>::Node(Node&& src) {
    value = src.value;
    next = src.next;
    next->prev = this;
    prev = nullptr;
    src.next = nullptr;
    
}


template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& src) {
    
}


template <typename T>
void Node<T>::append(const T& value) {
    if (!next)
        next = new Node(value, nullptr, this);
    else
        next->append(value);
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    if (!node.next)
        return os << node.value << "->|";
    os << node.value << "->";
    return os << *(node.next);
}




#endif /* Node_h */
