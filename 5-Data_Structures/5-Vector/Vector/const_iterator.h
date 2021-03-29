//
//  const_iterator.h
//  Vector
//
//  Created by Adam Saher on 2021-03-26.
//

#ifndef const_iterator_h
#define const_iterator_h

template <typename T> class Vector;


template <typename T>
class const_iterator {
    T* ptr;
    const Vector<T>* vector_ptr;
public:
    const_iterator(T*, const Vector<T>*);
    const_iterator operator++();
    bool operator<(const const_iterator&);
    T& operator*() const;
    
};


template <typename T>
const_iterator<T>::const_iterator(T* ptr, const Vector<T>* vec_ptr) {
    this->ptr = ptr;
    vector_ptr = vec_ptr;
}


template <typename T>
const_iterator<T> const_iterator<T>::operator++() {
    if (ptr < vector_ptr->data_ + vector_ptr->size())
        ++ptr;
    return *this;
}


template <typename T>
bool const_iterator<T>::operator<(const const_iterator<T>& other) {
    return ptr < other.ptr;
}


template <typename T>
T& const_iterator<T>::operator*() const {
    return *ptr;
}


#endif /* const_iterator_h */
