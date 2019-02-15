//
//  Iterator.hpp
//  LinkedList
//
//  Created by Adam Saher on 07/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

namespace Container {
    template <typename T>
    class Iterator : public Const_iterator<T> {
    protected:
        Iterator();
        Iterator(Node<T>* current, const LinkedList<T>*);
    };
    
    
    template <typename T>
    Iterator<T>::Iterator() {
        
    }
    
    
    template <typename T>
    Iterator<T>::Iterator(Node<T>* current, const LinkedList<T>* linked_lst) : Const_iterator<T>(current){}
    
    
    
}


#endif /* Iterator_h */
