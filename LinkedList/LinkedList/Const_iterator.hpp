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
    };
}


#endif /* Const_iterator_h */
