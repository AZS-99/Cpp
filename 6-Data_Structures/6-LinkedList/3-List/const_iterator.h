/*
    An iterator is just a wrapper, just like head & tail.
 
    Created by Adam Saher on 2021-03-19.
 */


#ifndef const_iterator_h
#define const_iterator_h

#include <optional>


template <typename T> class List;


template <typename T>
class const_iterator {
    Node<T>* current;
    const List<T>* list;             //const members have to be defined in an initializer list (check the constructor below)
    bool reversed;
    static const T null_dump;
    
protected:
    const_iterator(Node<T>*, const List<T>*, bool = false);
public:
    const_iterator<T> operator++();                //++x
    const_iterator<T> operator++(int);             //x++
    const_iterator<T> operator--();                //--x
    const_iterator<T> operator--(int);             //x++
    bool operator!=(const const_iterator&) const;
    bool operator==(const const_iterator&) const;
    T& operator*() const;
    friend List<T>;
};


//Static variables are defined as if they were methods, with dropping the 'static' keywrod.
template <typename T>
const T const_iterator<T>::null_dump = T{};


template <typename T>
const_iterator<T>::const_iterator(Node<T>* node, const List<T>* list, bool reversed_direction) : list (list)  {
    current = node;
    reversed = reversed_direction;
}


template <typename T>
const_iterator<T> const_iterator<T>::operator++() {
    if (reversed) {
        if (current)
            current = current->prev;
        else {
            current = list->head;
            reversed = false;
        }
    } else {
        if (current)
            current = current->nxt;
        else {
            current = list->tail;
            reversed = true;
        }
    }
    return *this;
}


template <typename T>
const_iterator<T> const_iterator<T>::operator++(int) {
    auto original_iterator = *this;
    if (reversed) {
        if (current)
            current = current->prev;
        else {
            current = list->head;
            reversed = false;
        }
    } else {
        if (current)
            current = current->nxt;
        else {
            current = list->tail;
            reversed = true;
        }
    }
    return original_iterator;
}


template <typename T>
const_iterator<T> const_iterator<T>::operator--()  {
    if (reversed) {
        if (current->nxt)
            current = current->nxt;
        else {
            current = current->prev;
            reversed = false;
        }
    } else {
        if (current->prev)
            current = current->prev;
        else {
            current = current->nxt;
            reversed = true;
        }
    }
    return *this;
}


template <typename T>
const_iterator<T> const_iterator<T>::operator--(int)  {
    auto original_iterator = *this;
    if (reversed) {
        if (current->nxt)
            current = current->nxt;
        else {
            current = current->prev;
            reversed = false;
        }
    } else {
        if (current->prev)
            current = current->prev;
        else {
            current = current->nxt;
            reversed = true;
        }
    }
    return original_iterator;
}


template <typename T>
bool const_iterator<T>::operator==(const const_iterator& other) const {
    return current == other.current;
}


template <typename T>
bool const_iterator<T>::operator!=(const const_iterator& other) const {
    return current != other.current;
}


template <typename T>
T& const_iterator<T>::operator*() const {
    return current? current->value : list->tail->value;
   
}

#endif /* const_iterator_h */
