//
//  Pair.h
//  Pair
//
//  Created by Adam Saher on 17/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Pair_h
#define Pair_h

template <typename T, typename V>
struct Pair {
    T first;
    V second;
    Pair(); //Important for T{} initialisation, like a Node of Pairs
    Pair(T&, V&);
};

template <typename T, typename V>
Pair<T, V>::Pair() {
    first = T{};
    second = V{};
}


template <typename T, typename V>
Pair<T, V>::Pair(T& first, V& second) {
    this->first = first;
    this->second = second;
}


template <typename T, typename V>
Pair<T, V> make_pair(T& first, V& value) {
    return Pair<T, V>(first, value);
}



#endif /* Pair_h */
