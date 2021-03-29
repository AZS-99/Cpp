//  NOTES ARE 
//
//  Created by Adam Saher on 2021-03-15.
//

#ifndef pair_hpp
#define pair_hpp

#include <stdio.h>

template <typename T, typename V>
struct Pair {
    T first;
    V second;
    Pair();
    Pair(const T&, const V&);
    void swap(Pair<T, V>&);
};


template <typename T, typename V>
Pair<T, V>::Pair() {
    first = T{};
    second = T{};
}


template <typename T, typename V>
Pair<T, V>::Pair(const T& first, const V& second) {
    this->first = first;
    this->second = second;
}


template <typename T, typename V>
void Pair<T, V>::swap(Pair<T, V>& other) {
    std::swap(first, other.first);
    std::swap(second, other.second);
}


//This is a fn, not a method.
template <typename T, typename V>
Pair<T, V> make_pair(const T& first, const V& second) {
    return Pair<T, V>(first, second);
}


/*
 Notes
 
 1- You can't have one constructor that has default values in the form:  Pair(const T& = T{}, const T& = T{})
    because that would make it possible to build a pair by passing only one argument.
 
 2- Pairs do allow empty constructors, try std::pair<std::string, int>();
    They are particularly important with nodes and arrays, like when initiating an array of empty pairs.
 */

#endif /* pair_hpp */
