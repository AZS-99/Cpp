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

namespace Container {
    template <typename T, size_t N>
    class Array {
        T array[N];
        size_t length;
    public:
        Array();
        Array(std::initializer_list<T>);
        bool empty() const;
        size_t size() const;
        size_t max_size() const;
        std::ostream& display(std::ostream& os) const;
        //return type HAS to be reference; otherwise, you can't manipulate array values.
        T& operator[](size_t i) {return array[i];};
        T& back();
        T& front();
        T* begin(); //Methods that return pointers can't be const
        T* end();
        void fill(T value);
        void push_back(T value);
        void swap(Array&);
    };
    
    
    template <typename T, size_t N>
    Array<T, N>::Array() {
        length = 0u;
    }
    
    
    //you need template specialisation for Char*
    template <typename T, size_t N>
    Array<T, N>::Array(std::initializer_list<T> args) {
        if (args.size() > N)
            throw std::string("Error: number of elements passed is more than array's size");
        length = 0u;
        for (auto& element : args)
            array[length++] = element;
    }
    
    
    template <typename T, size_t N>
    bool Array<T, N>::empty() const {
        return length == 0u;
    }
    
    
    template <typename T, size_t N>
    size_t Array<T, N>::size() const {
        return length;
    }
    
    
    template <typename T, size_t N>
    size_t Array<T, N>::max_size() const {
        return N;
    }
    
    
    template <typename T, size_t N>
    std::ostream& Array<T, N>::display(std::ostream& os) const {
        os << '[';
        size_t i;
        for (i = 0u; i < length - 1; ++i)
            os << array[i] << ", ";
        os << array[length - 1] << ']';
        return os;
    }
    
    
    template <typename T, size_t N>
    T& Array<T, N>::back() {
        return array[length - 1];
    }
    
    
    template <typename T, size_t N>
    T& Array<T, N>::front() {
        return array[0];
    }
    
    
    template <typename T, size_t N>
    T* Array<T, N>::begin() {
        return array;
    }
    
    
    template <typename T, size_t N>
    T* Array<T, N>::end() {
        return array + length;
    }
    
    
    template <typename T, size_t N>
    void Array<T, N>::fill(T value) {
        for (size_t i = 0u; i < N; ++i)
            array[i] = value;
        length = N;
    }
    
    
    template <typename T, size_t N>
    void Array<T, N>::push_back(T value) {
        if (length == N)
            throw std::string("Error: Array is full!");
        array[length++] = value;
    }
    
    
    template <typename T, size_t N>
    void Array<T, N>::swap(Array& other) {
        
        for (auto i = 0u; i < length; ++i)
            std::swap(array[i], other.array[i]);
    }
    
    
    template <typename T, size_t N>
    std::ostream& operator<<(std::ostream& os, Array<T, N> arr) {
        arr.display(os);
        return os;
    }
}

#endif /* array_hpp */
