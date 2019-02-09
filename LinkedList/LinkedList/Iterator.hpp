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
        Iterator(Node<T>* current) : Const_iterator<T>(current) {}
        
    };
}


#endif /* Iterator_h */
