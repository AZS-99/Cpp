//
//  node.h
//  BST
//
//  Created by Adam Saher on 2021-04-11.
//

#ifndef node_h
#define node_h

template <typename U> class BST;



template <typename T>
class BSTnode {
    T value;
    BSTnode<T>* right;
    BSTnode<T>* left;
public:
    BSTnode(const T& = T{}, BSTnode<T>* = nullptr, BSTnode<T>* = nullptr);
    unsigned furthest_grandchild_ordinal() const;
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const BSTnode<U>&);
    
    friend BST<T>;
};



template <typename T>
BSTnode<T>::BSTnode(const T& value, BSTnode<T>* right, BSTnode<T>* left) : value(value), right(right), left(left) {};


template <typename T>
unsigned BSTnode<T>::furthest_grandchild_ordinal() const {
    return this? std::max(left->furthest_grandchild_ordinal(), right->furthest_grandchild_ordinal()) + 1 : 0;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const BSTnode<T>& bst) {
    return os << bst.value;
}



#endif /* node_h */
