//
//  array.hpp
//  Array
//
//  Created by Adam Saher on 17/12/2018.
//  Copyright © 2018 Adam Saher. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#include <iostream>
#include <experimental/iterator>


template <typename T, unsigned N>
class Array {
    T _array[N]{};
    unsigned _length;
    
public:
    //No pointers --> Doesn't need the 5 constructors.
    Array ();
    Array (std::initializer_list<T>);
    Array (const Array&);
    Array (Array&&);
    Array& operator=(const Array&);
    bool empty() const;
    unsigned size() const;
    unsigned max_size() const;
    //return type HAS to be reference; otherwise, you can't manipulate array values.
    T& operator[](size_t i) {return _array[i];};
    T& back();
    T& front();
    T* begin(); //Methods that return pointers can't be const
    T* end();
    void fill(T value);
    void push_back(T value);
    void swap(Array&);
    
    template <typename U, unsigned M>
    friend std::ostream& operator<<(std::ostream&, const Array<U, M>&);
};


template <typename T, unsigned N>
Array<T, N>::Array() {
    std::cout << "Empty Constructor" << std::endl;
    _length = 0u;
}


//you need template specialisation for Char*
template <typename T, unsigned N>
Array<T, N>::Array(std::initializer_list<T> args) {
    std::cout << "initaliser list constructor" << std::endl;
    if (args.size() > N)
        throw std::string("Error: number of elements passed is more than array's size");
    _length = 0u; //since we have to iterate args anyway, no point of _length = args.size()
    for (auto& element : args)
        _array[_length++] = element;
}


template <typename T, unsigned N>
Array<T, N>::Array(const Array<T, N>& src) {
    std::cout << "Copy constructor" << std::endl;
    if (std::size(src._array) <= std::size(this->_array)) {
        std::copy(std::begin(src._array), std::end(src._array), std::begin(_array));
        _length = src._length;
    }
}


template <typename T, unsigned N>
Array<T, N>::Array(Array<T, N>&& src) {
    std::cout << "Move Constructor" << std::endl;
    std::swap (src._array, _array);
    _length = src._length;
    src._length = 0u;
}


template <typename T, unsigned N>
Array<T, N>& Array<T, N>::operator=(const Array& src) {
    std::cout << "Copy assignment" << std::endl;
    std::copy(std::begin(src._array), std::end(src._array), std::begin(_array));
    _length = src._length;
    return *this;
}



template <typename T, unsigned N>
bool Array<T, N>::empty() const {
    return _length == 0u;
}


template <typename T, unsigned N>
unsigned Array<T, N>::size() const {
    return _length;
}


template <typename T, unsigned N>
unsigned Array<T, N>::max_size() const {
    return N;
}


template <typename T, unsigned N>
T& Array<T, N>::back() {
    return _array[_length - 1];
}


template <typename T, unsigned N>
T& Array<T, N>::front() {
    return _array[0];
}


template <typename T, unsigned N>
T* Array<T, N>::begin() {
    return _array;
}


template <typename T, unsigned N>
T* Array<T, N>::end() {
    return _array + _length;
}


template <typename T, unsigned N>
void Array<T, N>::fill(T value) {
    for (size_t i = 0u; i < N; ++i)
        _array[i] = value;
    _length = N;
}


template <typename T, unsigned N>
void Array<T, N>::push_back(T value) {
    if (_length == N)
        throw std::string("Error: Array is full!");
    _array[_length++] = value;
}


template <typename T, unsigned N>
void Array<T, N>::swap(Array& other) {
    for (auto i = 0u; i < _length; ++i)
        std::swap(_array[i], other.array[i]);
}

    
template <typename T, unsigned N>
std::ostream& operator<<(std::ostream& os, const Array<T, N>& a) {
    os << '[';
    if (a._length > 0) {
        for (auto i = 0u; i < a._length - 1; ++i)
            os << a._array[i] << ", ";
        os << a._array[a._length - 1];
    }
    return os << ']';
}



#endif /* array_hpp */
